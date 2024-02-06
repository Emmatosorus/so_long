/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 14:48:00 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

static int		count_lines(char *file_path)
{
	int		fd;
	int 	count[2];
	char 	*str;

	count[0] = 0;
	count[1] = 0;
	str = NULL;
	fd = open(file_path, O_RDONLY);
	while (str != NULL || (count[0] == 0 && count[1]++ == 0))
	{
		str = get_next_line(fd);
		if (str != NULL)
		{
			count[0]++;
			free(str);
		}
	}
	close(fd);
	return (count[0]);
}

static void	get_map_layout(t_main **main)
{
	char 	*line;
	int 	fd;
	int 	count[2];

	line = NULL;
	count[0] = 0;
	count[1] = 0;
	(*main)->map->map = \
		(char **)malloc((*main)->map->map_size[1] * sizeof(char *));
	if (!(*main)->map->map)
		error_exit(main, "Malloc has failed : main_parse.c : 49");
	fd = open((*main)->map->file_path, O_RDONLY);
	while (line != NULL || (count[0] == 0 && count[1] == 0))
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			(*main)->map->map[count[0]++] = ft_strdup(line);
			free(line);
		}
		count[1]++;
	}
	close(fd);
}

static void	rm_cr(t_main **main)
{
	int count[2];

	count[0] = 0;
	while ((*main)->map->map_size[1] > count[0])
	{
		count[1] = 0;
		while ((*main)->map->map[count[0]][count[1]] != '\0')
		{
			if ((*main)->map->map[count[0]][count[1]] == '\n')
				(*main)->map->map[count[0]][count[1]] = '\0';
			count[1]++;
		}
		count[0]++;
	}
}

static void	map_init(t_main **main)
{
	(*main)->map->map = NULL;
	(*main)->map->file_path = "levels/";
	(*main)->map->player = 0;
	(*main)->map->coins = 0;
	(*main)->map->exit = 0;
	(*main)->map->foe = 0;
}

void	map_parse(char *filename, t_main **main)
{
	map_init(main);
	(*main)->map->file_path = ft_strjoin((*main)->map->file_path, filename);
	if (!(*main)->map->file_path)
		error_exit(main, \
			"Malloc has failed : ft_strjoin.c : main_parse.c : 95");
	(*main)->map->map_size[1] = count_lines((*main)->map->file_path);
	get_map_layout(main);
	rm_cr(main);
	verify_map(main);
	solve_map(main);
}

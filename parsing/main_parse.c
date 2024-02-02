/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 19:04:46 by epolitze         ###   ########.fr       */
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

static void	get_map_layout(t_parse *map)
{
	char 	*line;
	int 	fd;
	int 	count[2];

	line = NULL;
	count[0] = 0;
	count[1] = 0;
	map->map = (char **)malloc(map->map_size[1] * sizeof(char *));
	if (!map->map)
		error_exit(map);
	fd = open(map->file_path, O_RDONLY);
	while (line != NULL || (count[0] == 0 && count[1] == 0))
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			map->map[count[0]++] = ft_strdup(line);
			free(line);
		}
		count[1]++;
	}
	close(fd);
}

static void	rm_cr(t_parse *map)
{
	int count[2];

	count[0] = 0;
	while (map->map_size[1] > count[0])
	{
		count[1] = 0;
		while (map->map[count[0]][count[1]] != '\0')
		{
			if (map->map[count[0]][count[1]] == '\n')
				map->map[count[0]][count[1]] = '\0';
			count[1]++;
		}
		count[0]++;
	}
}

static void	map_init(t_parse *map)
{
	map->map = NULL;
	map->file_path = "levels/";
	map->player = 0;
	map->coins = 0;
	map->exit = 0;
	map->foe = 0;
}

void	map_parse(char *filename, t_parse *map)
{
	map_init(map);
	map->file_path = ft_strjoin(map->file_path, filename);
	map->map_size[1] = count_lines(map->file_path);
	get_map_layout(map);
	free(map->file_path);
	map->file_path = NULL;
	rm_cr(map);
	verify_map(map);
	solve_map(map);
}

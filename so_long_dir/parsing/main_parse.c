/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/13 15:20:25 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_lines(t_main *main)
{
	int		fd;
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	fd = open(main->map.file_path, O_RDONLY);
	if (fd == -1)
		error_exit(main, "Incorrect filename\n");
	while (str != NULL || count == 0)
	{
		errno = 0;
		str = get_next_line(fd);
		if (str != NULL)
		{
			count++;
			free(str);
		}
		if (errno != 0)
			map_error_exit(0, main, "37\n");
	}
	close(fd);
	return (count);
}

static void	get_map_layout(t_main *main)
{
	char	*line;
	int		fd;
	int		count;

	line = NULL;
	count = 0;
	main->map.s_map = \
		(char **)malloc(main->map.s_map_size[1] * sizeof(char *));
	if (!main->map.s_map)
		error_exit(main, "Malloc has failed : main_parse.c : 49\n");
	fd = open(main->map.file_path, O_RDONLY);
	if (fd == -1)
		error_exit(main, "Couldn't open file\n");
	while (line != NULL || count == 0)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			main->map.s_map[count++] = ft_strdup(line);
			free(line);
		}
		if (errno != 0)
			map_error_exit(count - 1, main, "67\n");
	}
	close(fd);
}

static void	rm_cr(t_main *main)
{
	int	count[2];

	count[0] = 0;
	while (main->map.s_map_size[1] > count[0])
	{
		count[1] = 0;
		while (main->map.s_map[count[0]][count[1]] != '\0')
		{
			if (main->map.s_map[count[0]][count[1]] == '\n')
				main->map.s_map[count[0]][count[1]] = '\0';
			count[1]++;
		}
		count[0]++;
	}
}

static void	map_init(t_main *main)
{
	main->map.s_map = NULL;
	main->map.map = NULL;
	main->map.c_pos = NULL;
	main->var.player.img = NULL;
	main->var.map.img = NULL;
	main->map.player = 0;
	main->map.coins = 0;
	main->map.exit = 0;
}

void	map_parse(char *filename, t_main *main)
{
	map_init(main);
	main->map.file_path = filename;
	main->map.s_map_size[1] = count_lines(main);
	if (main->map.s_map_size[1] < 3)
		error_exit(main, "File must have at least 3 lines\n");
	get_map_layout(main);
	rm_cr(main);
	verify_map(main);
	solve_map(main);
	main->map.map_size[0] = WIN_L / 64 + main->map.s_map_size[0];
	main->map.map_size[1] = WIN_H / 64 + main->map.s_map_size[1];
	allocate_map(main);
	copy_s_map_to_map(main);
	main->map.coins_left = main->map.coins;
}

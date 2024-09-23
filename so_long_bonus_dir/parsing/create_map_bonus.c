/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:57:27 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/19 17:05:57 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	error_free_map(t_parse *map, int y)
{
	if (map->map)
	{
		while (--y >= 0)
		{
			free(map->map[y]);
			map->map[y] = NULL;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	allocate_map(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	main->map.map = \
		(char **)malloc(main->map.map_size[1] * sizeof(char *));
	if (!main->map.map)
		error_exit(main, "Malloc has failed : create_map.c : 35\n");
	while (y < main->map.map_size[1])
	{
		x = -1;
		main->map.map[y] = (char *)malloc(main->map.map_size[0] \
			* sizeof(char));
		if (!main->map.map[y])
		{
			error_free_map(&main->map, y);
			error_exit(main, "Malloc has failed : create_map.c : 42\n");
		}
		while (++x < main->map.map_size[0])
			main->map.map[y][x] = 'B';
		y++;
	}
}

static int	is_corner(t_main *main, int y, int x)
{
	int	max_x;
	int	max_y;

	max_x = main->map.s_map_size[0] - 1;
	max_y = main->map.s_map_size[1] - 1;
	if ((y == 0 && x == 0) || (y == 0 && x == max_x) || \
		(y == max_y && x == 0) || (y == max_y && x == max_x))
		return (1);
	return (0);
}

void	copy_slot(t_main *main, int *s_pos, int *pos)
{
	if (s_pos[1] == 0 && s_pos[0] != 0 && s_pos[0] != \
		main->map.s_map_size[0] - 1)
		main->map.map[pos[1]][pos[0]] = 'U';
	else if (s_pos[1] == main->map.s_map_size[1] - 1 && s_pos[0] != 0
		&& s_pos[0] != main->map.s_map_size[0] - 1)
		main->map.map[pos[1]][pos[0]] = 'D';
	else if (s_pos[0] == main->map.s_map_size[0] - 1 && s_pos[1] != 0
		&& s_pos[1] != main->map.s_map_size[1] - 1)
		main->map.map[pos[1]][pos[0]] = 'R';
	else if (s_pos[0] == 0 && s_pos[1] != 0
		&& s_pos[1] != main->map.s_map_size[1] - 1)
		main->map.map[pos[1]][pos[0]] = 'L';
	else
		main->map.map[pos[1]][pos[0]] = main->map. \
			s_map[s_pos[1]][s_pos[0]];
	if (is_corner(main, s_pos[1], s_pos[0]) == 1)
		main->map.map[pos[1]][pos[0]] = 'B';
}

void	copy_s_map_to_map(t_main *main)
{
	int	s_pos[2];
	int	pos[2];

	s_pos[1] = 0;
	pos[1] = (main->map.map_size[1] / 2) - main->map.s_map_size[1] / 2;
	while (s_pos[1] < main->map.s_map_size[1])
	{
		s_pos[0] = 0;
		pos[0] = (main->map.map_size[0] / 2) - main->map.s_map_size[0] / 2;
		while (s_pos[0] < main->map.s_map_size[0])
		{
			copy_slot(main, s_pos, pos);
			if (main->map.map[pos[1]][pos[0]] == 'P')
			{
				main->map.p_pos[0] = pos[0];
				main->map.p_pos[1] = pos[1];
			}
			s_pos[0]++;
			pos[0]++;
		}
		s_pos[1]++;
		pos[1]++;
	}
}

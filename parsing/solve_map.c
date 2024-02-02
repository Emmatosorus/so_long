/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:08:25 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:08 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char **cpy_map(t_parse *map)
{
	int		i;
	char	**cpy;

	cpy = (char **)malloc(map->map_size[1] * sizeof(char *));
	if (!cpy)
		error_exit(map);
	i = 0;
	while (map->map_size[1] > i)
	{
		cpy[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (cpy);
}

static void	init_map_copy(t_parse *cpy, t_parse *map)
{
	cpy->map = cpy_map(map);
	cpy->file_path = NULL;
	cpy->map_size[0] = map->map_size[0];
	cpy->map_size[1] = map->map_size[1];
	cpy->player = map->player;
	cpy->p_pos[0] = map->p_pos[0];
	cpy->p_pos[1] = map->p_pos[1];
	cpy->coins = map->coins;
	cpy->exit = map->exit;
	cpy->enemy = map->enemy;
}

void	solve(t_parse *map, int x, int y)
{
	if (map->map[y][x] == 'C')
		map->coins--;
	if (map->map[y][x] == 'E')
		map->exit--;
	map->map[y][x] = '2';
	if (y - 1 > 0)
		if (map->map[y - 1][x] != '2' && map->map[y - 1][x] != '1')
			solve(map, x, y - 1);
	if (y + 1 < map->map_size[1])
		if (map->map[y + 1][x] != '2' && map->map[y + 1][x] != '1')
			solve(map, x, y + 1);
	if (x - 1 > 0)
		if (map->map[y][x - 1] != '2' && map->map[y][x - 1] != '1')
			solve(map, x - 1, y);
	if (x + 1 < map->map_size[0])
		if (map->map[y][x + 1] != '2' && map->map[y][x + 1] != '1')
			solve(map, x + 1, y - 1);
}

void	solve_map(t_parse *map)
{
	t_parse	map_copy;

	init_map_copy(&map_copy, map);
	solve(&map_copy, map_copy.p_pos[0], map_copy.p_pos[1]);
	if (map_copy.coins != 0 || map_copy.exit != 0)
	{
		ft_free(&map_copy);
		error_exit(map);
	}
	ft_free(&map_copy);
}
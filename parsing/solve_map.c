/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:08:25 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 15:05:24 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char **cpy_map(t_main **main)
{
	int		i;
	char	**cpy;

	cpy = (char **)malloc((*main)->map->map_size[1] * sizeof(char *));
	if (!cpy)
		error_exit(main, "Malloc has failed : solve_map.c : 20");
	i = 0;
	while ((*main)->map->map_size[1] > i)
	{
		cpy[i] = ft_strdup((*main)->map->map[i]);
		i++;
	}
	return (cpy);
}

static void	init_map_copy(t_parse *cpy, t_main **main)
{
	cpy->map = cpy_map(main);
	cpy->file_path = NULL;
	cpy->map_size[0] = (*main)->map->map_size[0];
	cpy->map_size[1] = (*main)->map->map_size[1];
	cpy->player = (*main)->map->player;
	cpy->p_pos[0] = (*main)->map->p_pos[0];
	cpy->p_pos[1] = (*main)->map->p_pos[1];
	cpy->coins = (*main)->map->coins;
	cpy->exit = (*main)->map->exit;
	cpy->foe = (*main)->map->foe;
}

void	solve(t_parse *cpy, int x, int y)
{
	if (cpy->map[y][x] == 'C')
		cpy->coins--;
	if (cpy->map[y][x] == 'E')
		cpy->exit--;
	cpy->map[y][x] = '2';
	if (y - 1 > 0)
		if (cpy->map[y - 1][x] != '2' && cpy->map[y - 1][x] != '1')
			solve(cpy, x, y - 1);
	if (y + 1 < cpy->map_size[1])
		if (cpy->map[y + 1][x] != '2' && cpy->map[y + 1][x] != '1')
			solve(cpy, x, y + 1);
	if (x - 1 > 0)
		if (cpy->map[y][x - 1] != '2' && cpy->map[y][x - 1] != '1')
			solve(cpy, x - 1, y);
	if (x + 1 < cpy->map_size[0])
		if (cpy->map[y][x + 1] != '2' && cpy->map[y][x + 1] != '1')
			solve(cpy, x + 1, y - 1);
}

void	solve_map(t_main **main)
{
	t_parse	map_copy;

	init_map_copy(&map_copy, main);
	solve(&map_copy, map_copy.p_pos[0], map_copy.p_pos[1]);
	if (map_copy.coins != 0 || map_copy.exit != 0)
	{
		ft_free_map(&map_copy);
		error_exit(main, "Map isn't solvable");
	}
	ft_free_map(&map_copy);
}
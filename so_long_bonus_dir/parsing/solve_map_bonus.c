/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:08:25 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/12 17:13:42 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	cpy_map(t_main *main)
{
	int		i;
	char	**cpy;

	cpy = (char **)malloc(main->map.s_map_size[1] * sizeof(char *));
	if (!cpy)
		error_exit(main, "Malloc has failed : solve_map.c : 20");
	i = 0;
	while (main->map.s_map_size[1] > i)
	{
		cpy[i] = ft_strdup(main->map.s_map[i]);
		if (!cpy[i])
			cpy_error_exit(i, cpy, main, \
				"ft_strdup has failed : solve_map.c : 26");
		i++;
	}
	main->cpy.s_map = cpy;
}

static void	init_map_copy(t_main *main)
{
	cpy_map(main);
	main->cpy.map = NULL;
	main->cpy.file_path = NULL;
	main->cpy.s_map_size[0] = main->map.s_map_size[0];
	main->cpy.s_map_size[1] = main->map.s_map_size[1];
	main->cpy.player = main->map.player;
	main->cpy.p_pos[0] = main->map.p_pos[0];
	main->cpy.p_pos[1] = main->map.p_pos[1];
	main->cpy.coins = main->map.coins;
	main->cpy.exit = main->map.exit;
	main->cpy.foe = main->map.foe;
}

void	solve(t_parse *cpy, int x, int y)
{
	if (cpy->s_map[y][x] == 'C')
		cpy->coins--;
	if (cpy->s_map[y][x] == 'E')
		cpy->exit--;
	cpy->s_map[y][x] = '2';
	if (y - 1 > 0)
		if (cpy->s_map[y - 1][x] != '2' && cpy->s_map[y - 1][x] != '1'
			&& cpy->s_map[y - 1][x] != 'F')
			solve(cpy, x, y - 1);
	if (y + 1 < cpy->s_map_size[1])
		if (cpy->s_map[y + 1][x] != '2' && cpy->s_map[y + 1][x] != '1'
			&& cpy->s_map[y + 1][x] != 'F')
			solve(cpy, x, y + 1);
	if (x - 1 > 0)
		if (cpy->s_map[y][x - 1] != '2' && cpy->s_map[y][x - 1] != '1'
			&& cpy->s_map[y][x - 1] != 'F')
			solve(cpy, x - 1, y);
	if (x + 1 < cpy->s_map_size[0])
		if (cpy->s_map[y][x + 1] != '2' && cpy->s_map[y][x + 1] != '1'
			&& cpy->s_map[y][x + 1] != 'F')
			solve(cpy, x + 1, y);
}

static void	free_cpy(t_main *main, bool error)
{
	int	i;

	i = -1;
	ft_free_map(&main->cpy);
	while (++i < main->cpy.s_map_size[1])
		free(main->cpy.s_map[i]);
	free(main->cpy.s_map);
	if (error)
		error_exit(main, "Map isn't solvable");
}

void	solve_map(t_main *main)
{
	init_map_copy(main);
	solve(&main->cpy, main->cpy.p_pos[0], main->cpy.p_pos[1]);
	if (main->cpy.coins != 0 || main->cpy.exit != 0)
		free_cpy(main, true);
	free_cpy(main, false);
}

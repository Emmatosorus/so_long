/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 19:01:22 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_xpm(t_main **main, char *path, int pos)
{
	(*main)->var->xpm[pos] = (t_xpm *)malloc(sizeof(t_xpm));
	if (!(*main)->var->xpm[pos])
		error_exit(main, "Malloc has failed : inits.c : 19");
	(*main)->var->xpm[pos]->img = mlx_xpm_file_to_image((*main)->var->mlx, \
		path, &(*main)->var->xpm[pos]->width, &(*main)->var->xpm[pos]->height);
}

void	xpm_inits(t_main **main)
{
	(*main)->var->xpm = (t_xpm **)malloc(15 * sizeof(t_xpm *));
	if (!(*main)->var->xpm)
		error_exit(main, "Malloc has failed : inits.c : 26");
	make_xpm(main, "./sprites/actor/actor_down.xpm", 0);
	make_xpm(main, "./sprites/actor/actor_down_rev.xpm", 1);
	make_xpm(main, "./sprites/actor/actor_up.xpm", 2);
	make_xpm(main, "./sprites/actor/actor_up_rev.xpm", 3);
	make_xpm(main, "./sprites/actor/actor_right.xpm", 4);
	make_xpm(main, "./sprites/actor/actor_right_rev.xpm", 5);
	make_xpm(main, "./sprites/actor/actor_left.xpm", 6);
	make_xpm(main, "./sprites/actor/actor_left_rev.xpm", 7);
	make_xpm(main, "./sprites/world/empty.xpm", 8);
	make_xpm(main, "./sprites/world/wall.xpm", 9);
	make_xpm(main, "./sprites/world/exit.xpm", 10);
	make_xpm(main, "./sprites/world/coin_1.xpm", 11);
	make_xpm(main, "./sprites/world/coin_2.xpm", 12);
	make_xpm(main, "./sprites/world/coin_3.xpm", 13);
	make_xpm(main, "./sprites/world/coin_4.xpm", 14);
}

void	window_init(t_main	**main)
{
	(*main)->var->mlx = mlx_init();
	(*main)->var->win = mlx_new_window((*main)->var->mlx, \
		64 * (*main)->map->map_size[0], \
		64 * (*main)->map->map_size[1], "It's so long..");
	if (!(*main)->var->win)
		error_exit(main, "MLX has failed us once more : inits.c : 50");
}

void	main_init(t_main **main)
{
	window_init(main);
	xpm_inits(main);
	(*main)->var->player_x = 0;
	(*main)->var->player_y = 0;
	(*main)->var->key_w = false;
	(*main)->var->key_a = false;
	(*main)->var->key_s = false;
	(*main)->var->key_d = false;
}

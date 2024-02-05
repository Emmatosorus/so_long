/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/05 18:24:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_xpm(t_var *var, char *path, int pos)
{
	var->xpm[pos]->img = mlx_xpm_file_to_image(var->mlx, path, \
		&var->xpm[pos]->width, &var->xpm[pos]->height);
}

void	xpm_inits(t_var *var)
{
	var->xpm = (t_xpm **)malloc(6 * sizeof(t_xpm *));
	if (!var->xpm)
		game_error_exit(var);
	// initialise all the sprites
	make_xpm(var, "./sprites/actor/actor_down.xpm", 0);
	make_xpm(var, "./sprites/actor/actor_down_rev.xpm", 1);
	make_xpm(var, "./sprites/actor/actor_up.xpm", 2);
	make_xpm(var, "./sprites/actor/actor_up_rev.xpm", 3);
	make_xpm(var, "./sprites/actor/actor_right", 4);
	make_xpm(var, "./sprites/actor/actor_right_rev.xpm", 5);
	make_xpm(var, "./sprites/actor/actor_left.xpm", 6);
	make_xpm(var, "./sprites/actor/actor_left_rev.xpm", 7);
	make_xpm(var, "./sprites/world/empty.xpm", 8);
	make_xpm(var, "./sprites/world/wall.xpm", 9);
	make_xpm(var, "./sprites/world/exit.xpm", 10);
	make_xpm(var, "./sprites/world/coin_1.xpm", 11);
	make_xpm(var, "./sprites/world/coin_2.xpm", 12);
	make_xpm(var, "./sprites/world/coin_3.xpm", 13);
	make_xpm(var, "./sprites/world/coin_4.xpm", 14);
}

void	window_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1920, 1600, "It's so long..");
}

void	main_init(t_var *var)
{
	window_init(var);
	xpm_inits(var);
	var->map_x = 0;
	var->map_y = 0;
	var->Key_W = false;
	var->Key_A = false;
	var->Key_S = false;
	var->Key_D = false;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/08 18:43:20 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_xpm(t_main **main, char *path, int pos)
{
	(*main)->var->xpm[pos] = (t_xpm *)malloc(sizeof(t_xpm));
	if (!(*main)->var->xpm[pos])
		error_exit(main, "Malloc has failed : inits.c : 17");
	(*main)->var->xpm[pos]->data = (t_data *)malloc(sizeof(t_data));
	if (!(*main)->var->xpm[pos]->data)
		error_exit(main, "Malloc has failed : inits.c : 20");
	(*main)->var->xpm[pos]->img = mlx_xpm_file_to_image((*main)->var->mlx, \
		path, &(*main)->var->xpm[pos]->width, &(*main)->var->xpm[pos]->height);
	if (!(*main)->var->xpm[pos]->img)
		error_exit(main, "MLX has failed us once more : inits.c : 23");
	(*main)->var->xpm[pos]->height = 0;
	(*main)->var->xpm[pos]->width = 0;
	(*main)->var->xpm[pos]->data->bits_per_pixel = 0;
	(*main)->var->xpm[pos]->data->line_length = 0;
	(*main)->var->xpm[pos]->data->endian = 0;
	(*main)->var->xpm[pos]->data->addr = mlx_get_data_addr( \
		(*main)->var->xpm[pos]->img, \
		&(*main)->var->xpm[pos]->data->bits_per_pixel, \
		&(*main)->var->xpm[pos]->data->line_length, \
		&(*main)->var->xpm[pos]->data->endian);
	if (!(*main)->var->xpm[pos]->data->addr)
		error_exit(main, "MLX has failed us once more : inits.c : 32");
}

void	xpm_inits(t_main **main)
{
	(*main)->var->xpm = (t_xpm **)malloc(20 * sizeof(t_xpm *));
	if (!(*main)->var->xpm)
		error_exit(main, "Malloc has failed : inits.c : 43");
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
	make_xpm(main, "./sprites/world/forest.xpm", 15);
	make_xpm(main, "./sprites/world/forest_up.xpm", 16);
	make_xpm(main, "./sprites/world/forest_down.xpm", 17);
	make_xpm(main, "./sprites/world/forest_right.xpm", 18);
	make_xpm(main, "./sprites/world/forest_left.xpm", 19);
}

void	window_init(t_main	**main)
{
	(*main)->var->mlx = mlx_init();
	if (!(*main)->var->mlx)
		error_exit(main, "MLX has failed us once more : inits.c : 65");
	(*main)->var->win = mlx_new_window((*main)->var->mlx, \
		WIN_L, \
		WIN_H, "It's so long..");
	if (!(*main)->var->win)
		error_exit(main, "MLX has failed us once more : inits.c : 68");
}

void	main_init(t_main **main)
{
	(*main)->var->player_x = WIN_L / 2 - 32;
	(*main)->var->player_y = WIN_H / 2 - 32;
	window_init(main);
	xpm_inits(main);
	map_img_init(main);
	player_img_init(main);
	(*main)->var->map_x = (*main)->var->player_x - \
		((*main)->map->p_pos[0] * 64);
	(*main)->var->map_y = (*main)->var->player_y - \
		((*main)->map->p_pos[1] * 64);
	(*main)->var->key_w = false;
	(*main)->var->key_a = false;
	(*main)->var->key_s = false;
	(*main)->var->key_d = false;
}

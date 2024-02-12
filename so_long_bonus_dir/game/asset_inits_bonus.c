/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_inits_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:56:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/12 16:08:29 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	map_img_init(t_main *main)
{
	main->var.map.bits_per_pixel = 0;
	main->var.map.line_length = 0;
	main->var.map.endian = 0;
	if (((main->map.map_size[1]) * 64) * \
		((main->map.map_size[0]) * 64) > 375000000)
		error_exit(main, "Map is too big");
	main->var.map.img = mlx_new_image(main->var.mlx, \
		64 * (main->map.map_size[0]), 64 * (main->map.map_size[1]));
	if (!main->var.map.img)
		error_exit(main, "Failed to create map image : asset_inits_bonus.c");
	main->var.map.addr = mlx_get_data_addr(\
		main->var.map.img, \
		&main->var.map.bits_per_pixel, \
		&main->var.map.line_length, \
		&main->var.map.endian);
	if (!main->var.map.addr)
		error_exit(main, \
			"Couldn't get map image address : asset_inits_bonus.c");
}

void	player_img_init(t_main *main)
{
	main->var.player.bits_per_pixel = 0;
	main->var.player.line_length = 0;
	main->var.player.endian = 0;
	main->var.player.img = mlx_new_image(main->var.mlx, 64, 64);
	if (!main->var.player.img)
		error_exit(main, "Couldn't create player image : asset_inits_bonus.c");
	main->var.player.addr = mlx_get_data_addr(\
		main->var.player.img, \
		&main->var.player.bits_per_pixel, \
		&main->var.player.line_length, \
		&main->var.player.endian);
	if (!main->var.player.addr)
		error_exit(main, \
			"Couldn't get player image address : asset_inits_bonus.c");
}

void	make_banners(t_main *main)
{
	make_xpm(main, "sprites/assets/move_background.xpm", 21);
	make_xpm(main, "sprites/assets/heart.xpm", 22);
	make_xpm(main, "sprites/assets/heart_background.xpm", 23);
	make_xpm(main, "sprites/assets/credits.xpm", 24);
}

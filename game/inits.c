/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 18:48:15 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_inits(t_var *var)
{
	// initialise all the sprites
}

void	window_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1900, 1500, "It's so long..");
	//var.map.img = mlx_xpm_file_to_image(var.mlx, PLAYER_PATH, &width, &height);
	//img.adr = mlx_get_data_addr(var->map.img, &var->map.bpp, &var->map.line_len, &var->map.endian);
}

void	main_init(t_var *var)
{
	window_init(var);

	var->map_x = 0;
	var->map_y = 0;
	var->Key_W = false;
	var->Key_A = false;
	var->Key_S = false;
	var->Key_D = false;
}

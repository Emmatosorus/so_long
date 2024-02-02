/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:41:30 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 17:42:00 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game(t_parse *map)
{
	t_var	*var;

	main_init(var);
	//var.map.img = mlx_new_image(var.mlx, 64, 64);

	//mlx_loop_hook(var.mlx, /* function that updates screen*/, &var);

	//mlx_put_image_to_window(var->mlx, var->win, var->map.img, 200 + var->player_x, 200 + var->player_y);
	//ft_move(var);
	//mlx_hook(var.win, 2, 1L<<0, ft_key_press, &var);
	//mlx_hook(var.win, 3, 1L<<1, ft_key_release, &var);
	//mlx_hook(var.win, 17, 0L, ft_close, &var);
	//mlx_loop(var.mlx);
}
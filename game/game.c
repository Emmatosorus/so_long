/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:41:30 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 17:18:31 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_ref(t_main *main)
{
	ft_move(main);
	mlx_put_image_to_window(main->var.mlx, main->var.win, \
		main->var.map.img, main->var.map_x, main->var.map_y);
	put_coins(main);
	build_player(main);
	//ft_printf("coins left : %d\n",main->map.coins_left);
	return (0);
}

void	game(t_main *main)
{
	main_init(main);
	build_map(main);

	mlx_loop_hook(main->var.mlx, ft_ref, main);
	mlx_hook(main->var.win, 2, 1L<<0, ft_key_press, main);
	mlx_hook(main->var.win, 3, 1L<<1, ft_key_release, main);
	mlx_hook(main->var.win, 17, 0L, ft_close, main);
	mlx_loop(main->var.mlx);
}

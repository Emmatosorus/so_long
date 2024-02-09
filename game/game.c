/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:41:30 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 22:55:54 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	ft_time(t_main *main)
{
	static int	loops = 0;
	double		func;

	loops++;
	func = (((-26 / 33) * main->map.a_coins) + 411);
	//printf("func : %f\n", func);
	if (loops > func)
		loops = 0;
	if (loops < func * 0.25)
		return (11);
	else if (loops < func * 0.5)
		return (12);
	else if (loops < func * 0.75)
		return (13);
	return (14);
	main->map.a_coins = 0;
}


int	ft_ref(t_main *main)
{
	int		img;
	char	*nb;

	img = ft_time(main);
	ft_move(main);
	mlx_put_image_to_window(main->var.mlx, main->var.win, \
		main->var.map.img, main->var.map_x, main->var.map_y);
	put_coins(main, img);
	build_player(main);
	mlx_string_put(main->var.mlx, main->var.win, 5, 13, 0xffffff, \
		"Move : ");
	nb = ft_itoa(main->var.moves / 64);
	mlx_string_put(main->var.mlx, main->var.win, 45, 15, 0xffffff, nb);
	free(nb);
	return (0);
}

void	game(t_main *main)
{
	main_init(main);
	build_map(main);

	mlx_loop_hook(main->var.mlx, ft_ref, main);
	mlx_hook(main->var.win, 2, 1L << 0, ft_key_press, main);
	mlx_hook(main->var.win, 3, 1L << 1, ft_key_release, main);
	mlx_hook(main->var.win, 17, 0L, ft_close, main);
	mlx_loop(main->var.mlx);
}

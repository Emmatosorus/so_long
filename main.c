/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/01 18:17:59 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game()
{
	//map_init(&var);
	//window_init(&var);
	//var.map.img = mlx_new_image(var.mlx, 64, 64);

	//mlx_loop_hook(var.mlx, /* function that updates screen*/, &var);

	//mlx_put_image_to_window(var->mlx, var->win, var->map.img, 200 + var->player_x, 200 + var->player_y);
	//ft_move(var);
	//mlx_hook(var.win, 2, 1L<<0, ft_key_press, &var);
	//mlx_hook(var.win, 3, 1L<<1, ft_key_release, &var);
	//mlx_hook(var.win, 17, 0L, ft_close, &var);
	//mlx_loop(var.mlx);
}

int	main(int ac, char **av)
{
	//t_var	var;
	t_parse	map;

	if (ac != 2)
		exit(EXIT_FAILURE);
	// only take .ber files
	map_parse(av[1], &map);
	//game();
	error_exit(&map);
	return (0);
}


//1 verifie la map
//2 init mon image
//3 je lance monjeux et le boulce infini
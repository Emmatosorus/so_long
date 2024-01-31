/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/31 18:15:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close(t_var *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

int ft_key_press(int keycode, t_var *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == KEY_W)
	{
		vars->Key_W = true;
	}
	else if (keycode == KEY_A)
	{
		vars->Key_A = true;
	}
	else if (keycode == KEY_S)
	{
		vars->Key_S = true;
	}
	else if (keycode == KEY_D)
	{
		vars->Key_D = true;
	}
	return (0);
}

int	ft_key_release(int keycode, t_var *vars)
{
	if (keycode == KEY_W)
		vars->Key_W = false;
	else if (keycode == KEY_A)
		vars->Key_A = false;
	else if (keycode == KEY_S)
		vars->Key_S = false;
	else if (keycode == KEY_D)
		vars->Key_D = false;
	return (0);
}

int	main(void)
{
	t_var	var;

	var.player_x = 200;
	var.player_y = 200;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1900, 1500, "It's so long..");

	spawn_window(&var);

	mlx_loop_hook(var.mlx, spawn_window, &var);
	mlx_hook(var.win, 2, 1L<<0, ft_key_press, &var);
	mlx_hook(var.win, 3, 1L<<1, ft_key_release, &var);
	mlx_hook(var.win, 17, 0L, ft_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
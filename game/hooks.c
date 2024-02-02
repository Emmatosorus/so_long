/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:43:03 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 17:43:38 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_var *var)
{
	if (var->Key_W)
		var->map_y--;
	if (var->Key_A)
		var->map_x--;
	if (var->Key_S)
		var->map_y++;
	if (var->Key_D)
		var->map_x++;
}

int ft_close(t_var *vars)
{
	mlx_destroy_image(vars->mlx, vars->map_img.img);
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
		vars->Key_W = true;
	else if (keycode == KEY_A)
		vars->Key_A = true;
	else if (keycode == KEY_S)
		vars->Key_S = true;
	else if (keycode == KEY_D)
		vars->Key_D = true;
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
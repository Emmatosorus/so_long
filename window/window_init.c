/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/01 16:09:08 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	map_init(t_var *var)
{
	var->map_x = 0;
	var->map_y = 0;
	var->Key_W = false;
	var->Key_A = false;
	var->Key_S = false;
	var->Key_D = false;
}

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

void window_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1900, 1500, "It's so long..");
	//var.map.img = mlx_xpm_file_to_image(var.mlx, PLAYER_PATH, &width, &height);
	//img.adr = mlx_get_data_addr(var->map.img, &var->map.bpp, &var->map.line_len, &var->map.endian);
}

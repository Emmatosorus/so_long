/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/31 18:17:20 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_var *var)
{
	if (var->Key_W)
		var->player_y--;
	if (var->Key_A)
		var->player_x--;
	if (var->Key_S)
		var->player_y++;
	if (var->Key_D)
		var->player_x++;
}

int	spawn_window(t_var *var)
{
	t_data	img;

	img.img = mlx_new_image(var->mlx, 200, 200);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_clear_window(var->mlx, var->win);

	ft_move(var);

	mlx_string_put(var->mlx, var->win, var->player_x, var->player_y, 0xba28bd, "LOVE");
	mlx_put_image_to_window(var->mlx, var->win, img.img, 0, 0);
	mlx_destroy_image(var->mlx, img.img);
	return (0);
}

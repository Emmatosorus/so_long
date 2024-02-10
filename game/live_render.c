/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:33:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 13:10:12 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	what_player(void)
{
	return (0);
}

void	build_player(t_main *main)
{
	int				img;
	int				p[2];
	unsigned int	color;

	p[1] = 0;
	img = what_player();
	while (p[1] < 64)
	{
		p[0] = 0;
		while (p[0] < 64)
		{
			color = *(unsigned int *)(main->var.xpm[img]->data.addr + \
				(p[1] * main->var.xpm[img]->data.line_length + p[0] \
				* 4));
			if (color != 0xff000000)
				mlx_pixel_put(main->var.mlx, main->var.win, \
					main->var.player_x + p[0], main->var.player_y \
					+ p[1], color);
			p[0]++;
		}
		p[1]++;
	}
}

static int	is_in_window(int x, int y)
{
	if (x > -64 && x < WIN_L + 64)
		if (y > -64 && y < WIN_H + 64)
			return (1);
	return (0);
}

void	put_coins(t_main *main, int img)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < main->map.coins)
	{
		x = main->map.c_pos[i][0];
		y = main->map.c_pos[i][1];
		if (((x != 0 || y != 0) || (x != 0 && y != 0)) \
			&& (is_in_window(x, y) == 1))
			mlx_put_image_to_window(main->var.mlx, main->var.win,\
				main->var.xpm[img]->img, x, y);
		i++;
	}
}

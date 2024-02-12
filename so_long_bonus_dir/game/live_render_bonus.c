/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:33:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/12 13:11:28 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	what_player(t_main *main)
{
	int	state;

	state = (main->var.moves / 64) % 2;
	if (main->var.key_w)
		main->var.p_img = 2 + state;
	else if (main->var.key_s)
		main->var.p_img = 0 + state;
	else if (main->var.key_a)
		main->var.p_img = 6 + state;
	else if (main->var.key_d)
		main->var.p_img = 4 + state;
}

void	build_player(t_main *main)
{
	int				p[2];
	unsigned int	color;

	p[1] = 0;
	what_player(main);
	while (p[1] < 64)
	{
		p[0] = 0;
		while (p[0] < 64)
		{
			color = *(unsigned int *)(main->var.xpm[main->var.p_img]->\
				data.addr + (p[1] * main->var.xpm[main->var.p_img]->\
				data.line_length + p[0] * 4));
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
			mlx_put_image_to_window(main->var.mlx, main->var.win, \
				main->var.xpm[img]->img, x, y);
		i++;
	}
}

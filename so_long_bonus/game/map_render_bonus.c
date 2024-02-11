/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:19 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/11 19:46:06 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	what_img(int x, int y, char **map)
{
	char	c;

	x /= 64;
	y /= 64;
	c = map[y][x];
	if (c == '0' || c == 'P' || c == 'C')
		return (8);
	else if (c == '1')
		return (9);
	else if (c == 'E')
		return (10);
	else if (c == 'B')
		return (15);
	else if (c == 'U')
		return (16);
	else if (c == 'D')
		return (17);
	else if (c == 'R')
		return (18);
	else if (c == 'L')
		return (19);
	else
		return (20);
}

inline void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = (int)color;
}

void	put_asset(t_main *main, int img, int x, int y)
{
	int	pos[2];
	int	color;

	pos[1] = 0;
	while (pos[1] < 64)
	{
		pos[0] = 0;
		while (pos[0] < 64)
		{
			color = *(int *)(main->var.xpm[img]->data.addr + \
				(pos[1] * main->var.xpm[img]->data.line_length + pos[0] \
				* 4));
			my_mlx_pixel_put(&main->var.map, x + pos[0], y + pos[1], color);
			pos[0]++;
		}
		pos[1]++;
	}
}

void	build_map(t_main *main)
{
	int	pos[2];
	int x;
	int	y;
	int	img;

	pos[1] = 0;
	y = 0;
	while (pos[1] < 64 * main->map.map_size[1])
	{
		pos[0] = 0;
		x = 0;
		while (pos[0] < 64 * main->map.map_size[0])
		{
			img = what_img(pos[0], pos[1], main->map.map);
			put_asset(main, img, x, y);
			pos[0] += 64;
			x += 64;
		}
		pos[1] += 64;
		y += 64;
	}
}

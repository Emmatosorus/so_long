/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:19 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/07 18:59:45 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	what_img(int x, int y, char **map)
{
	char	c;

	x /= 64;
	y /= 64;
	c = map[y][x];
	if (c == '0' || c == 'P')
		return (8);
	else if (c == '1')
		return (9);
	else if (c == 'E')
		return (10);
	else if (c == 'C')
		return (11);
	else
		return (11); // return foe
}

inline void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{

	((int *)data->addr)[y * (data->line_length >> 2) + x] = (int)color;
}

void	put_asset(t_main **main, int img, int x, int y)
{
	int				pos[2];
	int	color;

	pos[1] = 0;
	while (pos[1] < 64)
	{
		pos[0] = 0;
		while (pos[0] < 64)
		{
			color = *(int *)((*main)->var->xpm[img]->data->addr + \
				(pos[1] * (*main)->var->xpm[img]->data->line_length + pos[0] \
				* 4));
			my_mlx_pixel_put((*main)->var->map, x + pos[0], y + pos[1], color);
			pos[0]++;
		}
		pos[1]++;
	}
}

void	build_map(t_main **main)
{
	int	pos[2];
	int x;
	int	y;
	int	img;

	pos[1] = 0;
	y = 0;
	while (pos[1] < 64 * (*main)->map->map_size[1])
	{
		pos[0] = 0;
		x = 0;
		while (pos[0] < 64 * (*main)->map->map_size[0])
		{
			img = what_img(pos[0], pos[1], (*main)->map->map);
			put_asset(main, img, x, y);
			pos[0] += 64;
			x += 64;
		}
		pos[1] += 64;
		y += 64;
	}
}

//void	build_map(t_main **main)
//{
//	int	pos[2];
//	int x;
//	int	y;
//	int	img;
//
//	pos[1] = 0;
//	y = (WIN_H - (64 * (*main)->map->map_size[1])) / 2;
//	while (pos[1] < 64 * (*main)->map->map_size[1])
//	{
//		pos[0] = 0;
//		x = (WIN_L - (64 * (*main)->map->map_size[0])) / 2;
//		while (pos[0] < 64 * (*main)->map->map_size[0])
//		{
//			img = what_img(pos[0], pos[1], (*main)->map->map);
//			mlx_put_image_to_window((*main)->var->mlx, (*main)->var->win, \
//				(*main)->var->xpm[img]->img, x, y);
//			pos[0] += 64;
//			x += 64;
//		}
//		pos[1] += 64;
//		y += 64;
//	}
//}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:19 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 15:29:12 by epolitze         ###   ########.fr       */
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

void	build_map(t_main **main)
{
	int	pos[2];
	int img;

	pos[0] = 0;
	pos[1] = 0;
	while (pos[1] < 64 * (*main)->map->map_size[1])
	{
		while (pos[0] < 64 * (*main)->map->map_size[0])
		{
			img = what_img(pos[0], pos[1], (*main)->map->map);
			mlx_put_image_to_window((*main)->var->mlx, (*main)->var->win, \
				(*main)->var->xpm[img]->img, pos[0], pos[1]);
			pos[0] += 64;
		}
		pos[0] = 0;
		pos[1] += 64;
	}
}

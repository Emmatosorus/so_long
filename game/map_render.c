/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:19 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/05 20:37:04 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_pixel(int x, int y, int color);
{
	/*HOW DO I PRINT A FUCKING PIXEL!!!!!!!!!!!!*/
}

void	put_sprite(int x, int y, int img_nb, t_var *var)
{
	int 	x_save;
	void	*img;

	img = var->xpm[img_nb]->img;
	x_save = x;
	while (y < y + 64)
	{
		while (x < x + 64)
		{
			put_pixel(x, y, /*HOW DO I GET THE FUCKING COLOR?????*/);
			x++;
		}
		x = x_save;
		y++;
	}

}

int	what_img(int x, int y, char **map, t_var *var)
{
	int 	img;
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
}

void	build_map(t_var *var, t_parse *map)
{
	int	pos[2];
	int img;

	pos[0] = 0;
	pos[1] = 0;
	var->map = mlx_new_image(var->mlx, 64*map->map_size[0], 64*map->map_size[1]);
	while (pos[1] < 64 * map->map_size[1])
	{
		while (pos[0] < 64 * map->map_size[0])
		{
			img = what_img(pos[0], pos[1], map->map, var);
			put_sprite(pos[0], pos[1], img, var);
			pos[0] += 64;
		}
		pos[0] = 0;
		pos[1] += 64;
	}
}

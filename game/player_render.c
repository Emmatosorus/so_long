/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:33:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 14:01:09 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	what_player(void)
{
	return (0);
}

static int	what_coin(void)
{
	return (11);
}

void	build_player(t_main **main)
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
			color = *(unsigned int *)((*main)->var->xpm[img]->data->addr + \
				(p[1] * (*main)->var->xpm[img]->data->line_length + p[0] \
				* 4));
			if (color != 0xff000000)
				mlx_pixel_put((*main)->var->mlx, (*main)->var->win, \
					(*main)->var->player_x + p[0], (*main)->var->player_y \
					+ p[1], color);
			p[0]++;
		}
		p[1]++;
	}
}

void	put_coins(t_main **main)
{
	int	i;
	int	img;

	i = 0;
	img = what_coin();
	while (i < (*main)->map->coins)
	{
		if (((*main)->map->c_pos[i][0] != 0 || (*main)->map->c_pos[i][1] != 0)\
			|| ((*main)->map->c_pos[i][0] != 0 && (*main)->map->c_pos[i][1] != 0))
		{
			
			mlx_put_image_to_window((*main)->var->mlx, (*main)->var->win, \
				(*main)->var->xpm[11]->img, (*main)->map->c_pos[i][0], \
				(*main)->map->c_pos[i][1]);
		}
		i++;
	}
}

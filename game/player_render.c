/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:33:06 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/07 19:08:31 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	what_player(void)
{
	return (0);
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
					(*main)->var->player_x + p[0], (*main)->var->player_y + p[1], color);
			p[0]++;
		}
		p[1]++;
	}
}

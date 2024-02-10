/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_loop_exits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:15:05 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 20:32:18 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_error_exit(int pos, t_main *main, char *reason)
{
	int	i;

	i = 0;
	while (i <= pos)
	{
		if (main->var.xpm[pos])
		{
			if (main->var.xpm[pos]->img)
				mlx_destroy_image(main->var.mlx, main->var.xpm[pos]->img);
			if (main->var.xpm[pos]->data.addr)
				free(main->var.xpm[pos]->data.addr);
			free(main->var.xpm[pos]);
			main->var.xpm[pos] = NULL;
		}
		i++;
	}
	if (main->var.xpm)
		free(main->var.xpm);
	main->var.xpm = NULL;
	error_exit(main, reason);
}

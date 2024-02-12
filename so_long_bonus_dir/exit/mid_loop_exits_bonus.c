/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_loop_exits_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:15:05 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/12 13:11:59 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	xpm_error_exit(int pos, t_main *main, char *reason)
{
	while (pos >= 0)
	{
		if (main->var.xpm[pos])
		{
			if (main->var.xpm[pos]->img)
				mlx_destroy_image(main->var.mlx, main->var.xpm[pos]->img);
			free(main->var.xpm[pos]);
			main->var.xpm[pos] = NULL;
		}
		pos--;
	}
	if (main->var.xpm)
		free(main->var.xpm);
	main->var.xpm = NULL;
	error_exit(main, reason);
}

void	cpy_error_exit(int pos, char **cpy, t_main *main, char *reason)
{
	while (pos >= 0)
	{
		free(cpy[pos]);
		pos--;
	}
	free(cpy);
	main->cpy.s_map = NULL;
	error_exit(main, reason);
}

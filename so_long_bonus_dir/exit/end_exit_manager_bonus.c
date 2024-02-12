/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit_manager_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:54:51 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/12 16:04:53 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	credits(t_main *main)
{
	struct timeval	time;
	int				delta;

	gettimeofday(&time, NULL);
	delta = (time.tv_usec - main->var.last_time.tv_usec) + \
		(time.tv_sec - main->var.last_time.tv_sec) * 1000000;
	if (delta >= 6500)
	{
		main->var.last_time = time;
		main->var.credits--;
	}
	if (main->var.credits < -3000)
		ft_close(main);
	mlx_put_image_to_window(main->var.mlx, main->var.win, \
			main->var.xpm[24]->img, -50, main->var.credits);
	return (0);
}

void	death_end(t_main *main)
{
	ft_printf("\x1b[31;1mOuch!\nBrambles hurt..\n\x1b[0m");
	ft_close(main);
}

void	end_game(t_main *main)
{
	static bool	j = true;

	if (j)
	{
		ft_printf("\x1b[32;1mCongratulations\n\x1b[0m");
		ft_printf("\x1b[32;1mYou completed this level in %d moves!\n\x1b[0m", \
		main->var.moves / 64);
		j = false;
	}
	mlx_loop_hook(main->var.mlx, credits, main);
}
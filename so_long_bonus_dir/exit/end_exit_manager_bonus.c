/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit_manager_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:54:51 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/13 14:52:50 by epolitze         ###   ########.fr       */
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
	ft_printf(1, "\x1b[31;1mOuch!\nBrambles hurt..\n\x1b[0m");
	ft_close(main);
}

void	end_game(t_main *main)
{
	static bool	j = true;

	if (j)
	{
		gettimeofday(&main->end, NULL);
		ft_printf(1, "\x1b[32;1mCongratulations\n\x1b[0m");
		ft_printf(1, \
			"\x1b[32;1mYou completed this level in %d moves!\n\x1b[0m", \
			(main->var.moves / 64) + 1);
		if (main->end.tv_usec > main->start.tv_usec)
			ft_printf(1, \
				"\x1b[32;1mAnd in %d seconds and %d miliseconds!\n\x1b[0m", \
					(main->end.tv_sec - main->start.tv_sec), \
					((main->end.tv_usec / 1000) - (main->start.tv_usec / 1000)));
		else
			ft_printf(1, \
				"\x1b[32;1mAnd in %d seconds and %d miliseconds!\n\x1b[0m", \
					(main->end.tv_sec - main->start.tv_sec), \
					((main->start.tv_usec / 1000) - (main->end.tv_usec / 1000)));
		j = false;
	}
	mlx_loop_hook(main->var.mlx, credits, main);
}

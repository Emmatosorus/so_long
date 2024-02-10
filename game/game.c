/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:41:30 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 14:49:57 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_time(t_main *main)
{
	static int		state = 11;
	struct timeval	time;
	int				delta;

	gettimeofday(&time, NULL);
	delta = (time.tv_usec - main->var.last_time.tv_usec) +\
		(time.tv_sec - main->var.last_time.tv_sec) * 1000000;
	if (delta >= 175000)
	{
		main->var.last_time = time;
		if (state == 11)
			state = 12;
		else if (state == 12)
			state = 13;
		else if (state == 13)
			state = 14;
		else
			state = 11;
	}
	return (state);
}


int	ft_ref(t_main *main)
{
	int		img;
	char	*nb;

	ft_move(main);
	mlx_put_image_to_window(main->var.mlx, main->var.win, \
		main->var.map.img, main->var.map_x, main->var.map_y);
	img = ft_time(main);
	put_coins(main, img);
	build_player(main);
	mlx_put_image_to_window(main->var.mlx, main->var.win, \
		main->var.xpm[21]->img, 0, 0);
	mlx_string_put(main->var.mlx, main->var.win, 5, 18, 0xffffff, \
		"Move : ");
	nb = ft_itoa(main->var.moves / 64);
	mlx_string_put(main->var.mlx, main->var.win, 45, 19, 0xffffff, nb);
	free(nb);
	return (0);
}

void	game(t_main *main)
{
	main_init(main);
	build_map(main);

	mlx_loop_hook(main->var.mlx, ft_ref, main);
	mlx_hook(main->var.win, 2, 1L << 0, ft_key_press, main);
	mlx_hook(main->var.win, 3, 1L << 1, ft_key_release, main);
	mlx_hook(main->var.win, 17, 0L, ft_close, main);
	mlx_loop(main->var.mlx);
}

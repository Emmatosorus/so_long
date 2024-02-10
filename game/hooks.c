/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:43:03 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 18:28:35 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move(t_main *main)
{
	int		p_y;
	int		p_x;

	p_y = main->var.player_y;
	p_x = main->var.player_x;
	main->var.speed = 1;
	if (main->var.key_shift)
		main->var.speed = 2;
	if (main->var.key_w)
		move_w(main, p_y, p_x);
	if (main->var.key_a)
		move_a(main, p_y, p_x);
	if (main->var.key_s)
		move_s(main, p_y, p_x);
	if (main->var.key_d)
		move_d(main, p_y, p_x);
	return (0);
}

int	ft_key_press(int keycode, t_main *main)
{
	if (keycode == KEY_ESC)
		ft_close(main);
	else if (keycode == KEY_SHIFT)
		main->var.key_shift = true;
	else if (keycode == KEY_W || keycode == A_UP)
		main->var.key_w = true;
	else if (keycode == KEY_A || keycode == A_LEFT)
		main->var.key_a = true;
	else if (keycode == KEY_S || keycode == A_DOWN)
		main->var.key_s = true;
	else if (keycode == KEY_D || keycode == A_RIGHT)
		main->var.key_d = true;
	return (0);
}

int	ft_key_release(int keycode, t_main *main)
{
	if (keycode == KEY_SHIFT)
		main->var.key_shift = false;
	else if (keycode == KEY_W || keycode == A_UP)
		main->var.key_w = false;
	else if (keycode == KEY_A || keycode == A_LEFT)
		main->var.key_a = false;
	else if (keycode == KEY_S || keycode == A_DOWN)
		main->var.key_s = false;
	else if (keycode == KEY_D || keycode == A_RIGHT)
		main->var.key_d = false;
	return (0);
}

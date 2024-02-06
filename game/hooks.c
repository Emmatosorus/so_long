/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:43:03 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 19:00:36 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_main **main)
{
	if ((*main)->var->key_w)
		(*main)->var->player_y--;
	if ((*main)->var->key_a)
		(*main)->var->player_x--;
	if ((*main)->var->key_s)
		(*main)->var->player_y++;
	if ((*main)->var->key_d)
		(*main)->var->player_x++;
}

int	ft_key_press(int keycode, t_main **main)
{
	if (keycode == 65307)
		ft_close(main);
	else if (keycode == KEY_W)
		(*main)->var->key_w = true;
	else if (keycode == KEY_A)
		(*main)->var->key_a = true;
	else if (keycode == KEY_S)
		(*main)->var->key_s = true;
	else if (keycode == KEY_D)
		(*main)->var->key_d = true;
	return (0);
}

int	ft_key_release(int keycode, t_main **main)
{
	if (keycode == KEY_W)
		(*main)->var->key_w = false;
	else if (keycode == KEY_A)
		(*main)->var->key_a = false;
	else if (keycode == KEY_S)
		(*main)->var->key_s = false;
	else if (keycode == KEY_D)
		(*main)->var->key_d = false;
	return (0);
}

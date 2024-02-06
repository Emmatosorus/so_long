/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:43:03 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 18:26:29 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_main **main)
{
	if ((*main)->var->Key_W)
		(*main)->var->player_y--;
	if ((*main)->var->Key_A)
		(*main)->var->player_x--;
	if ((*main)->var->Key_S)
		(*main)->var->player_y++;
	if ((*main)->var->Key_D)
		(*main)->var->player_x++;
}

int ft_key_press(int keycode, t_main **main)
{
	if (keycode == 65307)
		ft_close(main);
	else if (keycode == KEY_W)
		(*main)->var->Key_W = true;
	else if (keycode == KEY_A)
		(*main)->var->Key_A = true;
	else if (keycode == KEY_S)
		(*main)->var->Key_S = true;
	else if (keycode == KEY_D)
		(*main)->var->Key_D = true;
	return (0);
}

int	ft_key_release(int keycode, t_main **main)
{
	if (keycode == KEY_W)
		(*main)->var->Key_W = false;
	else if (keycode == KEY_A)
		(*main)->var->Key_A = false;
	else if (keycode == KEY_S)
		(*main)->var->Key_S = false;
	else if (keycode == KEY_D)
		(*main)->var->Key_D = false;
	return (0);
}
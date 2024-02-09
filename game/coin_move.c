/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:26:15 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 17:53:19 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	forget_coin(t_main *main, int i, int x, int y)
{
	main->map.c_pos[i][0] = 0;
	main->map.c_pos[i][1] = 0;
	main->map.coins_left--;
	main->map.map[y][x] = '0';
}

void	move_coins(t_main *main, char c)
{
	int	i;

	i = -1;
	if (c == 'w')
		while(++i < main->map.coins)
			if (main->map.c_pos[i][1] != 0 || main->map.c_pos[i][0] != 0)
				main->map.c_pos[i][1]++;
	if (c == 'a')
		while(++i < main->map.coins)
			if (main->map.c_pos[i][0] != 0 || main->map.c_pos[i][1] != 0)
				main->map.c_pos[i][0]++;
	if (c == 's')
		while(++i < main->map.coins)
			if (main->map.c_pos[i][1] != 0 || main->map.c_pos[i][0] != 0)
				main->map.c_pos[i][1]--;
	if (c == 'd')
		while(++i < main->map.coins)
			if (main->map.c_pos[i][0] != 0 || main->map.c_pos[i][1] != 0)
			main->map.c_pos[i][0]--;
}

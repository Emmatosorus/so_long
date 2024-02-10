/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:41 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 17:51:04 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy_collide(t_main *main)
{
	char	c;
	int		x;
	int		y;

	x = (((main->var.map_x - 1) * -1) + main->var.player_x + 32) / 64;
	y = ((main->var.map_y * -1) + main->var.player_y + 32) / 64;
	c = main->map.map[y][x];
	if (c != 'F')
		main->var.cd = false;
	if (c == 'F' && !main->var.cd)
	{
		if (c == 'F' && main->var.hp == 1)
			death_end(main);
		main->var.hp--;
		main->var.cd = true;
	}
	return (0);
}

int	wall_collide(t_main *main, char c, int x, int y)
{
	char	*walls;
	int		i;

	walls = "UDLR1\0";
	i = -1;
	if (c == 'C')
		while (++i < main->map.coins)
			if (((main->map.c_pos[i][0] - main->var.map_x) / 64) == x \
				&& ((main->map.c_pos[i][1] - main->var.map_y) / 64) == y)
				forget_coin(main, i, x, y);
	if (c == 'E' && main->map.coins_left == 0)
		end_game(main);
	i = -1;
	while (walls[++i] != '\0')
		if (c == walls[i])
			return (-1);
	return (0);
}
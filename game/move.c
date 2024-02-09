/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:04:32 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 18:04:57 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int		is_wall(t_main *main, char c, int x, int y)
{
	char	*walls;
	int		i;

	walls = "UDLR1\0";
	i = -1;
	if (c == 'C')
		while (++i < main->map.coins)
			if(((main->map.c_pos[i][0] - main->var.map_x)/64) == x \
				&& ((main->map.c_pos[i][1] - main->var.map_y )/64) == y)
				forget_coin(main, i, x, y);
	if (c == 'E' && main->map.coins_left == 0)
		end_game(main);
	i = -1;
	while (walls[++i] != '\0')
		if (c == walls[i])
			return (-1);
	return (0);
}

void	move_w(t_main *main, int p_y, int p_x)
{
	char	**ptr;
	int		y;
	int		x[2];

	ptr = main->map.map;
	y = (((main->var.map_y + 1) * -1) + p_y)/64;
	x[0] = ((main->var.map_x * -1) + p_x + 48)/64;
	x[1] = ((main->var.map_x * -1) + p_x + 16)/64;
	if (is_wall(main, ptr[y][x[0]], x[0], y) == 0)
	{
		if (is_wall(main, ptr[y][x[1]], x[1], y) == 0)
		{
			main->var.map_y++;
			move_coins(main, 'w');
		}
	}
}

void	move_a(t_main *main, int p_y, int p_x)
{
	char	**ptr;
	int		x;
	int		y[2];

	x = (((main->var.map_x + 1) * -1) + p_x + 16)/64;
	y[0] = ((main->var.map_y * -1) + p_y + 16)/64;
	y[1] = ((main->var.map_y * -1) + p_y + 48)/64;
	ptr = main->map.map;
	if (is_wall(main, ptr[y[0]][x], x, y[0]) == 0)
	{
		if (is_wall(main, ptr[y[1]][x], x, y[1]) == 0)
		{
			main->var.map_x++;
			move_coins(main, 'a');
		}
	}
}

void	move_s(t_main *main, int p_y, int p_x)
{
	char	**ptr;
	int		y;
	int		x[2];

	y = (((main->var.map_y - 1) * -1) + p_y)/64 + 1;
	x[0] = ((main->var.map_x * -1) + p_x + 16)/64;
	x[1] = ((main->var.map_x * -1) + p_x + 48)/64;
	ptr = main->map.map;
	if (is_wall(main, ptr[y][x[0]], x[0], y) == 0)
	{
		if (is_wall(main, ptr[y][x[1]], x[1], y) == 0)
		{
			main->var.map_y--;
			move_coins(main, 's');
		}
	}
}

void	move_d(t_main *main, int p_y, int p_x)
{
	char	**ptr;
	int		x;
	int		y[2];

	x = (((main->var.map_x - 1) * -1) + p_x + 48)/64;
	y[0] = ((main->var.map_y * -1) + p_y + 16)/64;
	y[1] = ((main->var.map_y * -1) + p_y + 48)/64;
	ptr = main->map.map;
	if (is_wall(main, ptr[y[0]][x], x, y[0]) == 0)
	{
		if (is_wall(main, ptr[y[1]][x], x, y[1]) == 0)
		{
			main->var.map_x--;
			move_coins(main, 'd');
		}
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:04:32 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/13 13:49:22 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_w(t_main *main, int p_y, int p_x)
{
	char					**ptr;
	int						y;
	int						x[2];
	struct timeval			time;
	static struct timeval	last_time;

	gettimeofday(&time, NULL);
	if ((time.tv_usec - last_time.tv_usec) + \
		(time.tv_sec - last_time.tv_sec) * 1000000 <= MOVE_SPEED)
		return ;
	gettimeofday(&last_time, NULL);
	ptr = main->map.map;
	y = (((main->var.map_y + main->var.speed) * -1) + p_y) / 64;
	x[0] = ((main->var.map_x * -1) + p_x + 48) / 64;
	x[1] = ((main->var.map_x * -1) + p_x + 16) / 64;
	if (wall_collide(main, ptr[y][x[0]], x[0], y) == 0)
	{
		if (wall_collide(main, ptr[y][x[1]], x[1], y) == 0)
		{
			main->var.map_y += main->var.speed;
			if (!main->var.key_s)
				main->var.moves += main->var.speed;
			move_coins(main, 'w');
		}
	}
}

void	move_a(t_main *main, int p_y, int p_x)
{
	char					**ptr;
	int						x;
	int						y[2];
	struct timeval			time;
	static struct timeval	last_time;

	gettimeofday(&time, NULL);
	if ((time.tv_usec - last_time.tv_usec) + \
		(time.tv_sec - last_time.tv_sec) * 1000000 <= MOVE_SPEED)
		return ;
	gettimeofday(&last_time, NULL);
	x = (((main->var.map_x + main->var.speed) * -1) + p_x + 16) / 64;
	y[0] = ((main->var.map_y * -1) + p_y + 16) / 64;
	y[1] = ((main->var.map_y * -1) + p_y + 48) / 64;
	ptr = main->map.map;
	if (wall_collide(main, ptr[y[0]][x], x, y[0]) == 0)
	{
		if (wall_collide(main, ptr[y[1]][x], x, y[1]) == 0)
		{
			main->var.map_x += main->var.speed;
			if (!main->var.key_d)
				main->var.moves += main->var.speed;
			move_coins(main, 'a');
		}
	}
}

void	move_s(t_main *main, int p_y, int p_x)
{
	char					**ptr;
	int						y;
	int						x[2];
	struct timeval			time;
	static struct timeval	last_time;

	gettimeofday(&time, NULL);
	if ((time.tv_usec - last_time.tv_usec) + \
		(time.tv_sec - last_time.tv_sec) * 1000000 <= MOVE_SPEED)
		return ;
	gettimeofday(&last_time, NULL);
	y = (((main->var.map_y - main->var.speed) * -1) + p_y) / 64 + 1;
	x[0] = ((main->var.map_x * -1) + p_x + 16) / 64;
	x[1] = ((main->var.map_x * -1) + p_x + 48) / 64;
	ptr = main->map.map;
	if (wall_collide(main, ptr[y][x[0]], x[0], y) == 0)
	{
		if (wall_collide(main, ptr[y][x[1]], x[1], y) == 0)
		{
			main->var.map_y -= main->var.speed;
			if (!main->var.key_w)
				main->var.moves += main->var.speed;
			move_coins(main, 's');
		}
	}
}

void	move_d(t_main *main, int p_y, int p_x)
{
	char					**ptr;
	int						x;
	int						y[2];
	struct timeval			time;
	static struct timeval	last_time;

	gettimeofday(&time, NULL);
	if ((time.tv_usec - last_time.tv_usec) + \
		(time.tv_sec - last_time.tv_sec) * 1000000 <= MOVE_SPEED)
		return ;
	gettimeofday(&last_time, NULL);
	x = (((main->var.map_x - main->var.speed) * -1) + p_x + 48) / 64;
	y[0] = ((main->var.map_y * -1) + p_y + 16) / 64;
	y[1] = ((main->var.map_y * -1) + p_y + 48) / 64;
	ptr = main->map.map;
	if (wall_collide(main, ptr[y[0]][x], x, y[0]) == 0)
	{
		if (wall_collide(main, ptr[y[1]][x], x, y[1]) == 0)
		{
			main->var.map_x -= main->var.speed;
			if (!main->var.key_a)
				main->var.moves += main->var.speed;
			move_coins(main, 'd');
		}
	}
}

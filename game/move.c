/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:04:32 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/08 17:32:18 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int		is_wall(char c)
{
	char	*walls;
	int		i;

	walls = "UDLR1\0";
	i = -1;
	while (walls[++i] != '\0')
		if (c == walls[i])
			return (-1);
	return (0);
}

void	move_w(t_main **main, int p_y, int p_x)
{
	char	**ptr;

	ptr = (*main)->map->map;
	if (is_wall(ptr[((((*main)->var->map_y + 1) * -1) + p_y)/64] \
		[(((*main)->var->map_x * -1) + p_x + 48)/64]) == 0)
		if (is_wall(ptr[((((*main)->var->map_y + 1) * -1) + p_y)/64] \
			[(((*main)->var->map_x * -1) + p_x + 16)/64]) == 0)
			(*main)->var->map_y++;
}

void	move_a(t_main **main, int p_y, int p_x)
{
	char	**ptr;

	ptr = (*main)->map->map;
	if (is_wall(ptr[(((*main)->var->map_y * -1) + p_y + 16)/64] \
		[((((*main)->var->map_x + 1) * -1) + p_x + 16)/64]) == 0)
		if (is_wall(ptr[(((*main)->var->map_y * -1) + p_y + 48)/64] \
			[((((*main)->var->map_x + 1) * -1) + p_x + 16)/64]) == 0)
			(*main)->var->map_x++;
}

void	move_s(t_main **main, int p_y, int p_x)
{
	char	**ptr;

	ptr = (*main)->map->map;
	if (is_wall(ptr[((((*main)->var->map_y - 1) * -1) + p_y)/64 + 1] \
		[(((*main)->var->map_x * -1) + p_x + 16)/64]) == 0)
		if (is_wall(ptr[((((*main)->var->map_y - 1) * -1) + p_y)/64 + 1] \
			[(((*main)->var->map_x * -1) + p_x + 48)/64]) == 0)
			(*main)->var->map_y--;
}

void	move_d(t_main **main, int p_y, int p_x)
{
	char	**ptr;

	ptr = (*main)->map->map;
	if (is_wall(ptr[(((*main)->var->map_y * -1) + p_y + 16)/64] \
		[((((*main)->var->map_x - 1) * -1) + p_x + 48)/64]) == 0)
		if (is_wall(ptr[(((*main)->var->map_y * -1) + p_y + 48)/64] \
			[((((*main)->var->map_x - 1) * -1) + p_x + 48)/64]) == 0)
			(*main)->var->map_x--;
}


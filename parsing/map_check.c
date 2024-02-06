/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:37:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 18:52:33 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_wall(t_main **main, int y)
{
	int		pos;
	char	*line;

	pos = 0;
	line = (*main)->map->map[y];
	while (line[pos] != '\0')
	{
		if (line[pos] != '1')
			error_exit(main, "Map isn't closed");
		pos++;
	}
}

void	count_assets(t_main **main, int x, int y)
{
	char	c;

	c = (*main)->map->map[y][x];
	if (c == 'P' && (*main)->map->player == 0)
	{
		(*main)->map->p_pos[0] = x;
		(*main)->map->p_pos[1] = y;
		(*main)->map->player++;
	}
	else if (c == 'E')
		(*main)->map->exit++;
	else if (c == 'C')
		(*main)->map->coins++;
	else if (c == 'F')
		(*main)->map->foe++;
	else if (c == '1' || c == '0')
		return ;
	else if (c == 'P' && (*main)->map->player != 1)
		multiple_pos_error(main);
	else
		error_exit(main, "Invalid argument");
}

void	is_closed_n_valid(t_main **main)
{
	int	pos[2];

	pos[1] = 0;
	is_wall(main, pos[1]);
	while (pos[1] < (*main)->map->map_size[1])
	{
		pos[0] = 0;
		while ((*main)->map->map[pos[1]][pos[0]])
		{
			if (pos[0] == 0 && (*main)->map->map[pos[1]][pos[0]] != '1')
				error_exit(main, "Map isn't closed");
			if (pos[0] == (*main)->map->map_size[0] - 1
				&& (*main)->map->map[pos[1]][pos[0]] != '1')
				error_exit(main, "Map isn't closed");
			count_assets(main, pos[0], pos[1]);
			pos[0]++;
		}
		if (pos[1] + 1 == (*main)->map->map_size[1])
			is_wall(main, pos[1]);
		pos[1]++;
	}
	if ((*main)->map->player != 1 || (*main)->map->exit != 1
		|| (*main)->map->coins < 1)
		multiple_pos_error(main);
}

void	check_len(t_main **main)
{
	int	line;
	int	len;

	line = 0;
	while (line < (*main)->map->map_size[1])
	{
		len = (int)ft_strlen((*main)->map->map[line]);
		if (line == 0)
			(*main)->map->map_size[0] = len;
		if ((*main)->map->map_size[0] != len)
			error_exit(main, "Map isn't a rectangle");
		line++;
	}
}

void	verify_map(t_main **main)
{
	check_len(main);
	is_closed_n_valid(main);
}

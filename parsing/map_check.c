/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:37:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 19:04:55 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	is_wall(t_parse *map, int y)
{
	int 	pos;
	char 	*line;

	pos = 0;
	line = map->map[y];
	while (line[pos] != '\0')
	{
		if (line[pos] != '1')
			error_exit(map);
		pos++;
	}
}

void	count_assets(t_parse *map, int x, int y)
{
	char c;

	c = map->map[y][x];
	if (c == 'P' && map->player == 0)
	{
		map->p_pos[0] = x;
		map->p_pos[1] = y;
		map->player++;
	}
	else if (c == 'E')
		map->exit++;
	else if (c == 'C')
		map->coins++;
	else if (c == 'F')
		map->foe++;
	else if (c == '1' || c == '0')
		return ;
	else
		error_exit(map);
}

void	is_closed_n_valid(t_parse *map)
{
	int pos[2];

	pos[1] = 0;
	is_wall(map, pos[1]);
	while (pos[1] < map->map_size[1])
	{
		pos[0] = 0;
		while (map->map[pos[1]][pos[0]])
		{
			if (pos[0] == 0 && map->map[pos[1]][pos[0]] != '1')
				error_exit(map);
			if (pos[0] == map->map_size[0] - 1 && map->map[pos[1]][pos[0]] != '1')
				error_exit(map);
			count_assets(map, pos[0], pos[1]);
			pos[0]++;
		}
		if (pos[1] + 1 == map->map_size[1])
			is_wall(map, pos[1]);
		pos[1]++;
	}
	if (map->player > 1 || map->exit > 1 || map->coins < 1)
		error_exit(map);
}

void	check_len(t_parse *map)
{
	int 	line;
	int 	len;

	line = 0;
	while (line < map->map_size[1])
	{
		len = (int)ft_strlen(map->map[line]);
		if (line == 0)
			map->map_size[0] = len;
		if (map->map_size[0] != len)
			error_exit(map);
		line++;
	}

}
void	verify_map(t_parse *map)
{
	check_len(map);
	is_closed_n_valid(map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:37:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/01 18:20:21 by epolitze         ###   ########.fr       */
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

void	is_rectangular_n_closed(t_parse *map)
{
	is_wall(map, 0);
	is_wall(map, map->map_size[1]);
}

//void	has_assests(t_parse *map);

void	verify_map(t_parse *map)
{
	is_rectangular_n_closed(map);
	//has_assests(map);
}
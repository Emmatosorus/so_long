/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exit_manager_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:06:24 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/11 19:46:06 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free_map(t_parse *map)
{
	int		i;

	i = 0;
	if (map->map)
	{
		while (map->map_size[1] > i)
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
	}
}

void	file_error_exit(char *reason)
{
	ft_printf("\x1b[31;1mError\n%s\n\x1b[0m", reason);
	exit(EXIT_FAILURE);
}

void	error_exit(t_main *main, char *reason)
{
	ft_free_s_map(&main->map);
	ft_free_map(&main->map);
	ft_free_xpm(main);
	ft_free_mlx(main);
	if (main->map.file_path != NULL)
		free(main->map.file_path);
	if (main->map.c_pos)
		free(main->map.c_pos);
	ft_printf("\x1b[31;1mError\n%s\n\x1b[0m", reason);
	exit(EXIT_FAILURE);
}

void	multiple_pos_error(t_main *main)
{
	if (main->map.player != 1)
	{
		ft_printf("\x1b[31;1m%d %s\n\x1b[0m", main->map.player, \
			"player spawn points instead of 1");
		error_exit(main, "");
	}
	if (main->map.exit != 1)
	{
		ft_printf("\x1b[31;1m%d %s\n\x1b[0m", main->map.exit, \
			"exits instead of 1");
		error_exit(main, "");
	}
	if (main->map.coins < 1)
		error_exit(main, "Map must have at least 1 coin");
}

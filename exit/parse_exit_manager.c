/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:06:24 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/07 13:56:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_parse *map)
{
	int		i;

	i = 0;
	while (map->map_size[1] > i)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
	map->map = NULL;
}

void	error_exit(t_main **main, char *reason)
{
	if (main)
	{
		ft_free_xpm(main);
		ft_free_mlx(main);
		if ((*main)->map)
		{
			if ((*main)->map->file_path != NULL)
				free((*main)->map->file_path);
			if ((*main)->map->map != NULL)
				ft_free_map((*main)->map);
		}
	}
	ft_printf("\x1b[31;1m%s\n\x1b[0m", reason);
	exit(EXIT_FAILURE);
}

void	success_exit(t_main **main)
{
	if ((*main)->map)
	{
		if ((*main)->map->file_path != NULL)
			free((*main)->map->file_path);
		if ((*main)->map->map != NULL)
			ft_free_map((*main)->map);
	}
	exit(EXIT_SUCCESS);
}

void	multiple_pos_error(t_main **main)
{
	if ((*main)->map->player != 1)
	{
		ft_printf("\x1b[31;1m%d %s\x1b[0m", (*main)->map->player, \
			"player spawn points instead of 1");
		error_exit(main, "");
	}
	if ((*main)->map->exit != 1)
	{
		ft_printf("\x1b[31;1m%d %s\x1b[0m", (*main)->map->exit, \
			"exits instead of 1");
		error_exit(main, "");
	}
	if ((*main)->map->coins < 1)
		error_exit(main, "Map must have at least 1 coin");
}

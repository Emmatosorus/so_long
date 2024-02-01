/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:06:24 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/01 18:23:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	ft_free(t_parse *map)
{
	int		i;

	i = 0;
	ft_printf("%d\n", map->map_size[1]);
	while (map->map_size[1] - 1 >= i)
	{
		ft_printf("%s\n", map->map[i]);
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	error_exit(t_parse *map)
{
	if (map->file_path != NULL)
		free(map->file_path);
	ft_free(map);
	exit(EXIT_FAILURE);
}
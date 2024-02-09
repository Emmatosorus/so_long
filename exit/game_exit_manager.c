/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 09:50:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_xpm(t_main **main)
{
	int	i;

	i = -1;
	if ((*main)->var->xpm)
	{
		while (++i < 20)
		{
			if ((*main)->var->xpm[i])
			{
				if ((*main)->var->xpm[i]->img && (*main)->var->mlx)
					mlx_destroy_image((*main)->var->mlx, (*main)->var->xpm[i]->img);
				if ((*main)->var->xpm[i]->data)
					free((*main)->var->xpm[i]->data);
				free((*main)->var->xpm[i]);
			}
		}
		free((*main)->var->xpm);
	}
}

void	ft_free_mlx(t_main **main)
{
	if ((*main)->var->mlx && (*main)->var->win && (*main)->var->player \
		&& (*main)->var->map)
	{
		mlx_destroy_image((*main)->var->mlx, (*main)->var->map->img);
		mlx_destroy_image((*main)->var->mlx, (*main)->var->player->img);
		mlx_destroy_window((*main)->var->mlx, (*main)->var->win);
		mlx_destroy_display((*main)->var->mlx);
		free((*main)->var->map);
		free((*main)->var->player);
		free((*main)->var->mlx);
	}
	free((*main)->var);
}

void	ft_free_s_map(t_parse *map)
{
	int		i;

	i = 0;
	if (map->s_map)
	{
		while (map->s_map_size[1] > i)
		{
			free(map->s_map[i]);
			map->s_map[i] = NULL;
			i++;
		}
		free(map->s_map);
	}
}

int	ft_close(t_main **main)
{
	ft_free_xpm(main);
	ft_free_mlx(main);
	ft_free_s_map((*main)->map);
	if ((*main)->map)
	{
		if ((*main)->map->file_path != NULL)
			free((*main)->map->file_path);
		if ((*main)->map->map != NULL)
			ft_free_map((*main)->map);
		if ((*main)->map->c_pos)
			free((*main)->map->c_pos);
		free((*main)->map);
	}
	free(*main);
	(void)main;
	exit(EXIT_SUCCESS);
	return (0);
}

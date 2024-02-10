/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 09:07:32 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_xpm(t_main *main)
{
	int	i;

	i = -1;
	if (main->var.xpm)
	{
		while (++i < 20)
		{
			if (main->var.xpm[i])
			{
				if (main->var.xpm[i]->img && main->var.mlx)
					mlx_destroy_image(main->var.mlx, main->var.xpm[i]->img);
				free(main->var.xpm[i]);
			}
		}
		free(main->var.xpm);
	}
}

void	ft_free_mlx(t_main *main)
{
	if (main->var.mlx && main->var.win)
	{
		mlx_destroy_image(main->var.mlx, main->var.map.img);
		mlx_destroy_image(main->var.mlx, main->var.player.img);
		mlx_destroy_window(main->var.mlx, main->var.win);
		mlx_destroy_display(main->var.mlx);
		free(main->var.mlx);
	}
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

int	ft_close(t_main *main)
{
	ft_free_xpm(main);
	ft_free_mlx(main);
	ft_free_s_map(&main->map);
	ft_free_map(&main->map);
	if (main->map.file_path != NULL)
		free(main->map.file_path);
	if (main->map.c_pos)
		free(main->map.c_pos);
	if (main->map.coins_left > 0)
		ft_printf("\x1b[36;1mGoodby! See you next time! ^^\n\x1b[0m");
	exit(EXIT_SUCCESS);
	return (0);
}

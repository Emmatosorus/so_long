/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:17 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/07 18:01:07 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_xpm(t_main **main)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		mlx_destroy_image((*main)->var->mlx, (*main)->var->xpm[i]->img);
		free((*main)->var->xpm[i]->data);
		free((*main)->var->xpm[i]);
	}
	free((*main)->var->xpm);
}

void	ft_free_mlx(t_main **main)
{
	mlx_destroy_image((*main)->var->mlx, (*main)->var->map->img);
	mlx_destroy_image((*main)->var->mlx, (*main)->var->player->img);
	mlx_destroy_window((*main)->var->mlx, (*main)->var->win);
	mlx_destroy_display((*main)->var->mlx);
	free((*main)->var->map);
	free((*main)->var->player);
	free((*main)->var->mlx);
	free((*main)->var);
}

int	ft_close(t_main **main)
{
	ft_free_xpm(main);
	ft_free_mlx(main);
	if ((*main)->map)
	{
		if ((*main)->map->file_path != NULL)
			free((*main)->map->file_path);
		if ((*main)->map->map != NULL)
			ft_free_map((*main)->map);
		free((*main)->map);
	}
	free(*main);
	(void)main;
	exit(EXIT_SUCCESS);
	return (0);
}

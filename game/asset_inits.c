/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:56:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/08 16:34:11 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_img_init(t_main **main)
{
	(*main)->var->map = (t_data *) malloc(sizeof(t_data));
	if (!(*main)->var->map)
		error_exit(main, "Malloc has failed : asset_inits.c : 19");
	(*main)->var->map->bits_per_pixel = 0;
	(*main)->var->map->line_length = 0;
	(*main)->var->map->endian = 0;
	(*main)->var->map->img = mlx_new_image((*main)->var->mlx, \
        64 * ((*main)->map->map_size[0]), 64 * ((*main)->map->map_size[1]));
	(*main)->var->map->addr = mlx_get_data_addr(\
        (*main)->var->map->img, \
        &(*main)->var->map->bits_per_pixel, \
        &(*main)->var->map->line_length, \
        &(*main)->var->map->endian);
}

void	player_img_init(t_main **main)
{
	(*main)->var->player = (t_data *) malloc(sizeof(t_data));
	if (!(*main)->var->player)
		error_exit(main, "Malloc has failed : asset_inits.c : 36");
	(*main)->var->player->bits_per_pixel = 0;
	(*main)->var->player->line_length = 0;
	(*main)->var->player->endian = 0;
	(*main)->var->player->img = mlx_new_image((*main)->var->mlx, 64, 64);
	(*main)->var->player->addr = mlx_get_data_addr(\
        (*main)->var->player->img, \
        &(*main)->var->player->bits_per_pixel, \
        &(*main)->var->player->line_length, \
        &(*main)->var->player->endian);
}
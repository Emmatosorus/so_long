/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@42student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:21:52 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/05 14:04:11 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_error_exit(t_var *var)
{
	ft_printf("Sorry, an Error occurred\n");
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	exit(EXIT_FAILURE);
}
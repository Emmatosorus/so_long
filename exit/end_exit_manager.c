/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:54:51 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/10 08:59:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_main *main)
{
	ft_printf("\x1b[32;1mCongratulations\n\x1b[0m");
	ft_printf("\x1b[32;1mYou completed this level in %d moves!\n\x1b[0m", \
		main->var.moves / 64);
	ft_close(main);
}
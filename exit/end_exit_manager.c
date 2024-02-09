/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:54:51 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 18:04:53 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_main *main)
{
	ft_printf("\x1b[32;1mCongratulations\n\x1b[0m");
	ft_close(main);
}
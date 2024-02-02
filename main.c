/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 17:39:22 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	//t_var	var;
	t_parse	map;

	if (ac != 2)
		exit(EXIT_FAILURE);
	// only take .ber files
	map_parse(av[1], &map);
	game(&map);
	success_exit(&map);
	return (0);
}


//1 verifie la map -/
//2 init mon image
//3 je lance monjeux et le boulce infini
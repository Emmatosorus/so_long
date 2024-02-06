/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/06 15:54:53 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_main_struct(t_main **main)
{
	*main = NULL;
	*main = (t_main *)malloc(sizeof(t_main));
	if (!*main)
		error_exit(main, "Malloc has failed : main.c : line 17");
	(*main)->map = (t_parse *)malloc(sizeof(t_parse));
	if (!(*main)->map)
		error_exit(main, "Malloc has failed : main.c : line 20");
	(*main)->var = (t_var *)malloc(sizeof(t_var));
	if (!(*main)->var)
		error_exit(main, "Malloc has failed : main.c : line 23");
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	// only take .ber files
	initialize_main_struct(&main);
	map_parse(av[1], &main);
	game(&main);
	success_exit(&main);
	return (0);
}


//1 verifie la map -/
//2 init mon image
//3 je lance monjeux et le boulce infini
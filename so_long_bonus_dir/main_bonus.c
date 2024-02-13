/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/13 14:27:29 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_file(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len <= 4)
		file_error_exit("Incorrect filename\n");
	if (filename[len - 1] != 'r')
		file_error_exit("Not the right file extension\n");
	if (filename[len - 2] != 'e')
		file_error_exit("Not the right file extension\n");
	if (filename[len - 3] != 'b')
		file_error_exit("Not the right file extension\n");
	if (filename[len - 4] != '.')
		file_error_exit("No file extension : .ber\n");
}

void	initialize_main_struct(t_main *main)
{
	main->var.mlx = NULL;
	main->var.win = NULL;
	main->var.xpm = NULL;
}

int	main(int ac, char **av)
{
	t_main	main;

	if (ac != 2)
	{
		ft_printf(2, "\x1b[31;1mError\nNo map was given\n\x1b[0m");
		exit(EXIT_FAILURE);
	}
	check_file(av[1]);
	initialize_main_struct(&main);
	map_parse(av[1], &main);
	game(&main);
	return (0);
}

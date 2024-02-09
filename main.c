/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:48 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/09 17:05:47 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		error_exit(NULL, "Not the right file extension");
	if (filename[len - 2] != 'e')
		error_exit(NULL, "Not the right file extension");
	if (filename[len - 3] != 'b')
		error_exit(NULL, "Not the right file extension");
	if (filename[len - 4] != '.')
		error_exit(NULL, "No file extension : .ber");
	if (ft_strchr(filename, '/') != NULL)
		error_exit(NULL, "File cannot be in other directory than /levels/");
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
		exit(EXIT_FAILURE);
	check_file(av[1]);
	initialize_main_struct(&main);
	map_parse(av[1], &main);
	game(&main);
	success_exit(&main);
	return (0);
}

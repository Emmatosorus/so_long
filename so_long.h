/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:51:05 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/31 18:06:24 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct	s_data
{
	void		*img;
	char		*adr;
	int			bpp;
	int 		line_len;
	int 		endian;
}				t_data;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	int 	player_x;
	int 	player_y;
	bool	Key_W;
	bool	Key_A;
	bool	Key_S;
	bool	Key_D;
}			t_var;

int	spawn_window(t_var *var);

#endif
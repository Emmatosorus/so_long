/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:51:05 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/02 16:50:37 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libs/minilibx/mlx.h"
# include "libs/libft/libft.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define PLAYER_PATH "./sprites/actor/actor_down.xpm"

typedef struct	s_parse
{
	char 		**map;
	char		*file_path;
	int 		map_size[2];
	int 		player;
	int			p_pos[2];
	int 		coins;
	int 		exit;
	int 		enemy;
}				t_parse;

typedef struct	s_img
{
	void		*img;
	char		*adr;
	int			bpp;
	int 		line_len;
	int 		endian;
}				t_img;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	t_img		map_img;
	int 		map_x;
	int 		map_y;
	bool		Key_W;
	bool		Key_A;
	bool		Key_S;
	bool		Key_D;
}				t_var;

void	ft_free(t_parse *map);
void	error_exit(t_parse *map);
void	success_exit(t_parse *map);
void	map_parse(char *filename, t_parse *map_layout);
void	verify_map(t_parse *map);
void	solve_map(t_parse *map);
void 	window_init(t_var *var);

#endif
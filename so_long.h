/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:51:05 by epolitze          #+#    #+#             */
/*   Updated: 2024/02/08 18:33:04 by epolitze         ###   ########.fr       */
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
# define WIN_H 1400
# define WIN_L 1920

typedef struct s_parse
{
	char		**map;
	char		**s_map;
	char		*file_path;
	int			s_map_size[2];
	int			map_size[2];
	int			player;
	int			p_pos[2];
	int			coins;
	int			exit;
	int			foe;
}				t_parse;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_xpm
{
	void	*img;
	t_data	*data;
	int		height;
	int		width;
}			t_xpm;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_xpm		**xpm;
	t_data		*map;
	int			map_x;
	int			map_y;
	t_data		*player;
	int 		player_x;
	int 		player_y;
	bool		key_w;
	bool		key_a;
	bool		key_s;
	bool		key_d;
}				t_var;

typedef struct s_main
{
	t_var	*var;
	t_parse	*map;
	t_parse	*cpy;
}			t_main;

/* Error Management */
void	ft_free_map(t_parse *map);
void	ft_free_s_map(t_parse *map);
void	multiple_pos_error(t_main **main);
void	error_exit(t_main **main, char *reason);
void	success_exit(t_main **main);
void	ft_free_mlx(t_main **main);
void	ft_free_xpm(t_main **main);
int		ft_close(t_main **main);

/* Parsing */
void	map_parse(char *filename, t_main **main);
void	verify_map(t_main **main);
void	solve_map(t_main **main);
void	allocate_map(t_main **main);
void	copy_s_map_to_map(t_main **main);

/* Initializations */
void	map_img_init(t_main **main);
void	player_img_init(t_main **main);

/* Game */
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	build_map(t_main **main);
void	build_player(t_main **main);
void	main_init(t_main **main);
void	game(t_main **main);
void	window_init(t_main **main);
int		ft_move(t_main **main);

/* User Input */
void	move_w(t_main **main, int p_y, int p_x);
void	move_a(t_main **main, int p_y, int p_x);
void	move_s(t_main **main, int p_y, int p_x);
void	move_d(t_main **main, int p_y, int p_x);
int		ft_key_press(int keycode, t_main **main);
int		ft_key_release(int keycode, t_main **main);

#endif
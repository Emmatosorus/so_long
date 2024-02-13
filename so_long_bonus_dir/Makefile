NAME = ../so_long_bonus

CC = cc

CFLAGS = -g3 -Wextra -Wall -Werror -O3

HDR = so_long_bonus.h

LIB_HDR = ../libs/libft/libft.h

LIB_AR = ../libs/libft/libft.a

FTLINKER = -L../libs/libft -lft

XINCLUDE = -I ../libs/minilibx/

XFLAG = -lXext -lX11 -lm

OBJ_DIR = .obj/

#--------Sources--------#

SRC = \
	main_bonus.c \
	exit/parse_exit_manager_bonus.c \
	exit/mid_loop_exits_bonus.c \
	exit/game_exit_manager_bonus.c \
	exit/end_exit_manager_bonus.c \
	parsing/main_parse_bonus.c \
	parsing/map_check_bonus.c \
	parsing/solve_map_bonus.c \
	parsing/create_map_bonus.c \
	game/game_bonus.c \
	game/hooks_bonus.c \
	game/inits_bonus.c \
	game/asset_inits_bonus.c \
	game/map_render_bonus.c \
	game/move_bonus.c \
	game/move_tools_bonus.c \
	game/coin_move_bonus.c \
	game/live_render_bonus.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

#---------Rules---------#

all : 
	$(MAKE) mlx
	$(MAKE) $(NAME)

$(OBJ_DIR)%.o: %.c $(HDR)
	mkdir -p $(OBJ_DIR)exit/ $(OBJ_DIR)parsing/ $(OBJ_DIR)game/
	$(CC) $(CFLAGS) $(XINCLUDE) -c $< -o $@

$(NAME) : $(OBJ) $(LIB_AR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(XINCLUDE) -L../libs/minilibx/ -lmlx $(XFLAG) $(FTLINKER)

mlx: force
	$(MAKE) -C ../libs/minilibx

$(LIB_AR): force
	$(MAKE) -C ../libs/libft

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean all re mlx force

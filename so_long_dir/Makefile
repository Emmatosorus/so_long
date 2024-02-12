NAME = ../so_long

CC = cc

CFLAGS = -g3 -Wextra -Wall -Werror -O3

HDR = so_long.h

LIB_HDR = ../libs/libft/libft.h

LIB_AR = ../libs/libft/libft.a

FTLINKER = -L../libs/libft -lft

XINCLUDE = -I ../libs/minilibx/

XFLAG = -lXext -lX11 -lm

OBJ_DIR = .obj/

#--------Sources--------#

SRC = \
	main.c \
	exit/parse_exit_manager.c \
	exit/mid_loop_exits.c \
	exit/game_exit_manager.c \
	parsing/main_parse.c \
	parsing/map_check.c \
	parsing/solve_map.c \
	parsing/create_map.c \
	game/game.c \
	game/hooks.c \
	game/inits.c \
	game/asset_inits.c \
	game/map_render.c \
	game/move.c \
	game/coin_move.c \
	game/live_render.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

#---------Rules---------#

all :
	$(MAKE) mlx
	$(MAKE) $(NAME)

$(OBJ_DIR)%.o: %.c $(HDR) $(LIB_AR)
	mkdir -p $(OBJ_DIR)exit/ $(OBJ_DIR)parsing/ $(OBJ_DIR)game/
	$(CC) $(CFLAGS) $(XINCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(XINCLUDE) -L../libs/minilibx/ -lmlx $(XFLAG) $(FTLINKER)

mlx:
	$(MAKE) -C ../libs/minilibx

$(LIB_AR): force
	$(MAKE) -C ../libs/libft

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean all re mlx force




NAME = so_long

CC = cc

CFLAGS = -Wextra -Wall -Werror -g3

HDR = so_long.h

LIB_HDR = libs/libft/libft.h

LIB_AR = libs/libft/libft.a

FTLINKER = -Llibs/libft -lft

XINCLUDE = -I libs/minilibx/

XFLAG = -lXext -lX11 -lm

#--------Sources--------#

SRC = \
	main.c \
	exit/parse_exit_manager.c \
	exit/game_exit_manager.c \
	parsing/main_parse.c \
	parsing/map_check.c \
	parsing/solve_map.c \
	game/game.c \
	game/hooks.c \
	game/inits.c \
	game/asset_inits.c \
	game/map_render.c \
	game/player_render.c

OBJ = $(SRC:%.c=%.o)

#---------Rules---------#

all : $(NAME)

%.o: %.c $(HDR) $(LIB_AR)
	$(CC) $(CFLAGS) $(XINCLUDE) -c $< -o $(<:.c=.o)

$(NAME) : mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(XINCLUDE) -Llibs/minilibx/ -lmlx $(XFLAG) $(FTLINKER)

mlx:
	$(MAKE) -C libs/minilibx

$(LIB_AR): force
	$(MAKE) -C libs/libft

clean:
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/minilibx clean
	rm -f $(OBJ)

fclean:
	$(MAKE) -C libs/libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re mlx force


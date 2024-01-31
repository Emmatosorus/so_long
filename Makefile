NAME = so_long

CC = cc

CFLAGS = -Wextra -Wall -Werror -g

HDR = so_long.h

LIB_HDR = libft/libft.h

LIB_AR = libft/libft.a

FTLINKER = -Llibft -lft

XINCLUDE = -I minilibx/

XFLAG = -lXext -lX11 -lm

#--------Sources--------#

SRC = \
	main.c \
	window/window_spawn.c

OBJ = $(SRC:%.c=%.o)

#---------Rules---------#

all : $(NAME)

%.o: %.c $(HDR) $(LIB_AR)
	$(CC) $(CFLAGS) $(XINCLUDE) -O3 -c $< -o $(<:.c=.o)

$(NAME) : mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(XINCLUDE) -Lminilibx/ -lmlx $(XFLAG) $(FTLINKER)

mlx: force
	$(MAKE) -C minilibx

$(LIB_AR): force
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean
	rm -f $(OBJ)

fclean:
	$(MAKE) -C libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re force


CC = cc 

CFLAGS = -Wextra -Wall -Werror

HDR = so_long.h 

NAME = so_long

#--------Sources--------#

SRC = \
	main.c

OBJ = (SRC:.c=.o)

#---------Rules---------#

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HDR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re
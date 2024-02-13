NAME = so_long

NAME_BONUS = so_long_bonus

all :
	$(MAKE) -C so_long_dir

bonus :
	$(MAKE) -C so_long_bonus_dir

mlx:
	$(MAKE) -C libs/minilibx

clean:
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/minilibx clean
	$(MAKE) -C so_long_dir clean
	$(MAKE) -C so_long_bonus_dir clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re mlx force

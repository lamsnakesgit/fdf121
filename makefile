NAME = ffdf
SRC = fdf.c ft_cw.c
FLG = -Wall -Wextra -Werror
DBG = -g
all: $(NAME)

$(NAME):
	gcc $(DBG) libft/libft.a minilibx_macos/libmlx.a -framework Appkit -framework opengl  $(SRC) -o $(NAME)
clean:
	rm $(NAME)
fclean: clean
#	rm $(NAME)
re: fclean all

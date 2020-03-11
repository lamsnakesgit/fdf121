NAME = ffdf
SRC = fdf.c ft_cw.c drawer.c press_fdf.c  ft_rotation.c ft_initd.c auxs.c\
	  data_get.c free.c
FLG = -Wall -Wextra -Werror
DBG = -g -O2 #-O3# -O2 -Ofast
F = -Ofast
all: $(NAME)

$(NAME):
	gcc $(DBG)   libft/libft.a minilibx_macos/libmlx.a -framework Appkit -framework opengl  $(SRC) -o $(NAME)
clean:
	rm $(NAME)
fclean: clean
#	rm $(NAME)
re: fclean all

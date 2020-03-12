NAME = ffdf
SRC = fdf.c ft_cw.c drawer.c press_fdf.c  ft_rotation.c ft_initd.c auxs.c\
	   free.c
FLG = -Wall -Wextra -Werror -O2
OBJ = $(SRC:.c=.o)
INC = fdf.h
CC = gcc
lib = libft

%.c: %.o $(INC)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INC) $(lib)
	make -C $(lib)
	$(CC) -o $(NAME) $(SRC) -L ./libft -lft -lmlx -framework Appkit -framework OpenGl $(FLG)
	#$(CC)  $(FLG)  libft/libft.a minilibx_macos/libmlx.a -framework Appkit -framework opengl  $(SRC) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

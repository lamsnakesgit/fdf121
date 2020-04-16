NAME = fdf
SRC		=	fdf.c drawer.c ft_cw.c press_fdf.c ft_initd.c \
				ft_rotation.c free.c auxs.c
OBJ		=	$(SRC:.c=.o)
INC		=	fdf.h
.PHONY: clean all fclean re
all:				libft/libft.a $(NAME)
libft/libft.a: libft
	@make -C libft/
$(NAME): libft $(OBJ) $(INC)
	gcc -Wall -Wextra -Werror $(OBJ) libft/libft.a \
	-lmlx -framework OpenGL -framework AppKit \
	-o $(NAME)
%.o: %.c libft $(INC)
	gcc -Wall -Wextra -Wextra -O2 -I $(INC) -o $@ -c $<
clean:
	@rm -f $(OBJ)

fclean:		clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re:					fclean all

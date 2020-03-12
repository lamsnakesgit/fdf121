SRC		=	fdf.c drawer.c ft_cw.c press_fdf.c ft_initd.c \
				ft_rotation.c free.c auxs.c
OBJ		=	$(SRC:.c=.o)
INC		=	fdf.h
all:				libft/libft.a fdf
libft/libft.a: libft
	@make -C libft/
fdf: libft $(OBJ) $(INC)
	gcc -Wall -Wextra -Werror $(OBJ) libft/libft.a \
	-lmlx -framework OpenGL -framework AppKit \
	-o fdf
%.o: %.c libft $(INC)
	gcc -Wall -Wextra -Wextra -O2 -I $(INC) -o $@ -c $<
clean:
	@rm -f $(OBJ)

fclean:		clean
	make -C libft/ fclean
	@rm -f fdf

re:					fclean all

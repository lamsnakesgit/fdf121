NAME = ffdf
SRC = fdf.c ft_cw.c drawer.c press_fdf.c  ft_rotation.c ft_initd.c auxs.c\
	   free.c
FLG = -Wall -Wextra -Werror -O2
OBJ = $(SRC:.c=.o)
INC = fdf.h
CC = gcc
lib = libft

.PHONY: all clean fclean re
%.o : %.c $(INC) lib
	$(CC) $(FLG) -I $(INC) -o $@ -c $<

all: $(NAME)

lib:
	make -C libft

$(NAME): $(OBJ) $(INC) $(lib)
	@make -C $(lib)
	$(CC) -o $(NAME) $(SRC) -L ./libft -lft -lmlx -framework Appkit -framework OpenGl $(FLG)
#%.o : %.c
#	$(CC) $(FLG) -I $(INC) -o $@ -c $<
clean:
	@make fclean -C $(lib)
	@rm $(OBJ)

fclean: clean
	@make fclean -C $(lib)
	@rm $(NAME)

re: fclean all

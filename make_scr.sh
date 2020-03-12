$(NAME): $(OBJ) $(INC) $(lib)
			make -C $(lib)
						$(CC) -o $(NAME) $(SRC) -L ./libft -lft -lmlx -framework Appkit -framework OpenGl $(FLG)
								#$(CC)  $(FLG)  libft/libft.a minilibx_macos/libmlx.a -framework Appkit -framework opengl  $(SRC) -o $(NAME)

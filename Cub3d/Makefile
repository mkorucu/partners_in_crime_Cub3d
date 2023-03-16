NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -L./mlx - lmlx - framework AppKit -framework OpenGL - g
RM		=	rm -rf
SRC		=	
OBJ		=	$(SRC:.c=.o)
LIBFT	=	lib/libft/libft.a
mlx		=	/lib/mlx/mlx.a

all:	$(NAME)

#colors

YELLOW = "\033[33m"
RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
RESET = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

(MLX):
		@make -C ./mlx

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo $(BLUE)cub3d is ready!

%.o: %.c $(INC)
	@echo $(RED)Complining [$<]
	@${CC} -c $< -o $@ -Wall -Werror -Wextra -g

clean:
	@$(RM) $(OBJ)
	@echo $(RED)Removed [$(OBJ)]

norm:
	@norminette $(SRC)
	@norminette cub3d.h
	@norminette libft/

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(MLX)
	@echo $(RED)Removed [$(NAME)]
	@make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re
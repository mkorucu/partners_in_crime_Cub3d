NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-L./mlx - lmlx - framework AppKit -framework OpenGL - g
RM		=	rm -rf
OBJ		=	$(SRC:.c=.o) $(GNL:.c=.o) 
LIBFT	=	lib/libft/libft.a
#mlx		=	/lib/mlx/mlx.a
GNL		=	lib/gnl/get_next_line_utils.c lib/gnl/get_next_line.c
SRC		=	main.c checkers/checkers.c checkers/extention_check.c checkers/check_characters.c checkers/check_walls.c

all:	$(NAME)

#colors

YELLOW = "\033[33m"
RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
RESET = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#(MLX):
#		@make -C ./mlx

$(LIBFT):
	@make -C lib/libft/

$(NAME): $(OBJ) $(LIBFT) #$(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo $(BLUE)cub3d is ready! $(RESET)

%.o: %.c $(INC)
	@echo $(GREEN)Complining [$<]
	@${CC} -c $< -o $@ -Wall -Werror -Wextra -g

clean:
	@$(RM) $(OBJ)
	@echo $(YELLOW)Removed [Objects]

norm:
	@norminette $(SRC)
	@norminette cub3d.h
	@norminette libft/

fclean: clean
	@$(RM) $(NAME)
#	@$(RM) $(MLX)
	@echo $(YELLOW)Removed [$(NAME)]
	@make fclean -C lib/libft/

re: fclean all

.PHONY: all, clean, fclean, re
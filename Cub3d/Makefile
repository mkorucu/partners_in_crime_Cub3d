NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -L./lib/mlx -lmlx -framework AppKit -framework OpenGL -g
RM		=	rm -rf
OBJ		=	$(SRC:.c=.o) $(GNL:.c=.o) $(CHECKS:.c=.o) $(FREE:.c=.o) $(INITS:.c=.o) $(LOOP:.c=.o)
LIBFT	=	lib/libft/libft.a
MLX		=	lib/mlx/libmlx.a
GNL		=	lib/gnl/get_next_line_utils.c lib/gnl/get_next_line.c
SRC		=	main.c
CHECKS	=	checkers/extension_check.c checkers/check_characters.c checkers/check_directions.c\
			checkers/checkers.c checkers/check_rgb.c checkers/check_is_open.c checkers/check_wall.c
FREE	=	free_error/free_array.c free_error/errors.c
INITS	=	init/import_map_file.c init/init_direction_vector.c init/init_textures.c init/setting_ceiling_floor.c
LOOP	=	loop/key_events.c loop/camera_orientation.c loop/press_keys.c loop/rotate_keys.c
all:	$(NAME)

#colors

YELLOW = "\033[33m"
RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
RESET = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:	$(NAME)

$(MLX):
		@make -C ./lib/mlx

$(LIBFT):
	@make -C lib/libft/

$(NAME): $(OBJ) $(LIBFT) $(MLX)
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
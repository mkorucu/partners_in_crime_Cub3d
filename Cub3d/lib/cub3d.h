#ifndef CUB3D_H
#define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define EXTENTION_ERROR 1
# define WALLS_MISMATCH 2
# define UNKNOWN_CHARACTER 3
# define DIRECTION_MISMATCH 4
typedef	struct	s_cub3d
{
	char	**map;
	int		xlen;
	int		ylen;
	int		fd;
}				t_cub3d;


int	checkers(t_cub3d *cub);
int	extention_check(char *map_name);
int	check_walls(t_cub3d *cub);
int	check_characters(t_cub3d *cub);
#endif
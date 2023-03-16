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

typedef	struct	s_cub3d
{
	char	**map;
}				t_cub3d;

#endif
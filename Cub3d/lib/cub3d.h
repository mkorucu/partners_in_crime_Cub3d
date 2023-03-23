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

# define VALID				0
# define EXTENTION_ERROR	1
# define WALLS_MISMATCH		2
# define UNKNOWN_CHARACTER	3
# define DIRECTION_MISMATCH	4
# define EMPTY_MAP			5
# define RGB_MISMATCH		6
# define CANNOT_OPEN		7
# define SURROUND_MISMATCH	8


typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_file
{
	int		fd_map;
	int		fd_east;
	int		fd_south;
	int		fd_north;
	int		fd_west;
	char	**map_file;
	char	*east;
	char	*south;
	char	*north;
	char	*west;
	char	*rgb_f;
	char	*rgb_c;
	t_rgb	f;
	t_rgb	c;
}				t_file;

typedef	struct	s_cub3d
{
	char	**map;
	char	start;
	int		start_x;
	int		start_y;
	int		map_heigh;
	t_file	*files;
}				t_cub3d;

void	free_array(char **arr);

/*					Checkers					*/
int	checkers(t_cub3d *cub);
int	extention_check(char *map_name);
int	check_characters(char **str, t_cub3d *cub);
int	check_directions(t_file *files);
int check_rgb(t_file *files);
int	check_is_open(t_file *files);
int	check_wall(t_cub3d *cub, char ch);
/* 					Free Functions				*/
void	free_cub(t_cub3d *cub);
void	free_files(t_file *files);
void	free_array(char **arr);

#endif
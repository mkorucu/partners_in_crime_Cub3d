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

# ifndef WIDTH
# define WIDTH 1920
# endif
# ifndef HEIGHT
# define HEIGHT 1080
# endif

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_key
{
	int	a;
	int	s;
	int	d;
	int	w;
	int	left;
	int	right;
}				t_key;

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

typedef struct s_image
{
	int		width;
	int		height;
	void	*image;
	char	*address;
	int		line;
	int		endian;
	int		bpp;
}				t_image;

typedef	struct	s_pos
{
	double	dir_x;
	double	dir_y;
	double	fov_x;
	double	fov_y;

}				t_pos;

typedef	struct	s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	start_direction;
	int		start_x;
	int		start_y;
	int		map_heigh;
	long	rgb_floor;
	long	rgb_ceil;
	t_pos	pos;
	t_key	keys;
	t_file	*files;
	t_image screen;
	t_image	part_of_map;
	t_image	walls[4];
	t_image	floor;
	t_image	ceiling;
}				t_cub3d;


void	free_array(char **arr);
void	errors(char *str);

/*					Checkers					*/
int		checkers(t_cub3d *cub);
int		extention_check(char *map_name);
int		check_characters(char **str, t_cub3d *cub);
int		check_directions(t_file *files);
int 	check_rgb(t_file *files);
int		check_is_open(t_file *files);
int		check_wall(t_cub3d *cub);

/* 					Free Functions				*/
void	free_cub(t_cub3d *cub);
void	free_files(t_file *files);
void	free_array(char **arr);

/*					Initializing				*/
int	import_map_file(t_cub3d **cub, char *map);
void	init_map_textures(t_cub3d *cub, t_image *s, t_image *pom);
void    init_wall_textures(t_cub3d *cub, t_file *file, t_image *walls);
void	start(t_cub3d *cub, t_file *files);

#endif
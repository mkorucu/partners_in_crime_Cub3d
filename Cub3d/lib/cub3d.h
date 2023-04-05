#ifndef CUB3D_H
# define CUB3D_H

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
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
# endif
# define VERTICAL 0
# define HORIZONTAL 1

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

typedef struct s_file
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
	void	*image;
	int		*address;
	int		line;
	int		endian;
	int		bpp;
}			t_image;

typedef struct s_key
{
	int	a;
	int	s;
	int	d;
	int	w;
	int	left;
	int	right;
}				t_key;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	fov_x;
	double	fov_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	char	wall_side;
	char	direction;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	double	rot_speed;
	double	move_speed;
	int		tex_y;
	int		color;
}		t_ray;

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	start_direction;
	int		map_heigh;
	long	rgb_floor;
	long	rgb_ceil;
	int		t_width;
	int		t_height;
	t_ray	ray;
	t_key	keys;
	t_file	*files;
	t_image	screen;
	t_image	walls[4];
	t_image	floor;
	t_image	ceiling;
}				t_cub3d;

void	free_array(char **arr);
void	errors(char *str);

/*					Checkers					*/
int		checkers(t_cub3d *cub);
int		extension_check(char *map_name);
int		check_characters(char **str, t_cub3d *cub);
int		check_directions(t_file *files);
int		check_rgb(t_file *files);
int		check_is_open(t_file *files);
int		check_wall(t_cub3d *cub);

/* 					Free Functions				*/
void	free_cub(t_cub3d *cub);
void	free_files(t_file *files);
void	free_array(char **arr);

/*					Initializing				*/
int		import_map_file(t_cub3d **cub, char *map);
void	init_textures(t_cub3d *cub, t_file *file, t_image *walls, t_image *s);
void	init_direction_vector(t_cub3d *cub);
void	setting_ceiling_floor(t_cub3d *cub);
void	start(t_cub3d *cub, t_file *files);
/*					Key Events					*/
int		release_key(int key, t_key *keys);
int		press_key(int key, t_key *keys);
void	key_direction(t_cub3d *cub);
void	press_direction_keys(t_cub3d *cub, t_ray *ray, int sign, char key);
void	rotation_keys(t_ray *ray, int sign);
int		ft_exit(void);
/*					Printing Map				*/
void	print_map(t_cub3d *cub);
void	camera_orientation(t_cub3d *cub, t_ray *ray, int x);
void	set_image(t_cub3d *cub, t_ray *ray);
void	line_calculator(t_ray *ray);
void	perform_dda(t_cub3d *cub, t_ray *ray);
void	side_checker(t_ray *ray);
void	print_to_screen(t_cub3d *cub, t_ray *ray, int j, int i);
#endif
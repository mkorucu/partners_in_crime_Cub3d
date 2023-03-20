#include "../lib/cub3d.h"

int	check_is_open(t_file *files)
{
	files->fd_east = open(files->east, O_RDONLY);
	files->fd_north = open(files->north, O_RDONLY);
	files->fd_south = open(files->south, O_RDONLY);
	files->fd_west = open(files->west, O_RDONLY);
	if ( files->fd_west < 0 || files->fd_south  < 0 || \
		files->fd_north < 0 || files->fd_east < 0)
		return (CANNOT_OPEN);
	else
		return (0);
}
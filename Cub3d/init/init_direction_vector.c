#include "../lib/cub3d.h"

void	init_direction_vector(t_cub3d *cub)
{
	if (cub->start_direction == 'N')
	{
		cub->ray.dir_y = -1;
		cub->ray.fov_x = 0.66;
	}
	if (cub->start_direction == 'W')
	{
		cub->ray.dir_x = -1;
		cub->ray.fov_y = 0.66;
	}
	if (cub->start_direction == 'S')
	{
		cub->ray.dir_y = 1;
		cub->ray.fov_x = -0.66;
	}
	if (cub->start_direction == 'E')
	{
		cub->ray.dir_x = 1;
		cub->ray.fov_y = -0.66;
	}
}
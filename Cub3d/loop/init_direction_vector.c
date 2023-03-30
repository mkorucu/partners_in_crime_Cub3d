#include "../lib/cub3d.h"

void	init_direction_vector(t_cub3d *cub)
{
	if (cub->start_direction == 'N')
	{
		cub->ray.dirX = -1;
		cub->ray.fovY = 0.66;
	}
	if (cub->start_direction == 'W')
	{
		cub->ray.dirY = -1;
		cub->ray.fovX = -0.66;
	}
	if (cub->start_direction == 'S')
	{
		cub->ray.dirX = 1;
		cub->ray.fovY = -0.90;
	}
	if (cub->start_direction == 'E')
	{
		cub->ray.dirY = 1;
		cub->ray.fovX = 0.66;
	}
}
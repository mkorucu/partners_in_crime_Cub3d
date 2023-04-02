#include "../lib/cub3d.h"

void	insert_character(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'W' \
			|| cub->map[i][j] == 'E' || cub->map[i][j] == 'S')
			{
				cub->ray.pos_x = i;
				cub->ray.pos_y = j;
				cub->start_direction = cub->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
}


void	init_direction_vector(t_cub3d *cub)
{
	if (cub->start_direction == 'N')
	{
		cub->ray.dir_x = -1;
		cub->ray.fov_y = 0.66;
	}
	if (cub->start_direction == 'W')
	{
		cub->ray.dir_y = -1;
		cub->ray.fov_x = -0.66;
	}
	if (cub->start_direction == 'S')
	{
		cub->ray.dir_x = 1;
		cub->ray.fov_y = -0.66;
	}
	if (cub->start_direction == 'E')
	{
		cub->ray.dir_y = 1;
		cub->ray.fov_x = 0.66;
	}
}

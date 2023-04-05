#include "../lib/cub3d.h"

void	press_direction_keys(t_cub3d *cub, t_ray *ray, int sign, char key)
{
	if (key == 'w' || key == 's')
	{
		if (cub->map[(int)(ray->pos_y)][(int)(ray->pos_x + \
		ray->dir_x * ray->move_speed * sign)] != '1')
			ray->pos_x += ray->dir_x * ray->move_speed * sign;
		if (cub->map[(int)(ray->pos_y + ray->dir_y * ray->move_speed * sign)] \
		[(int)(ray->pos_x)] != '1')
			ray->pos_y += ray->dir_y * ray->move_speed * sign;
	}
	if (key == 'a' || key == 'd')
	{
		if (cub->map[(int)(ray->pos_y)][(int)(ray->pos_x + \
		ray->fov_x * ray->move_speed * sign)] != '1')
			ray->pos_x += ray->fov_x * ray->move_speed * sign;
		if (cub->map[(int)(ray->pos_y + ray->fov_y * ray->move_speed * sign)] \
		[(int)(ray->pos_x)] != '1')
			ray->pos_y += ray->fov_y * ray->move_speed * sign;
	}
}

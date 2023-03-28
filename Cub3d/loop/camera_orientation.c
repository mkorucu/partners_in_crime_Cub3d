#include "../lib/cub3d.h"

void    camera_orientation(t_cub3d *cub, t_ray *ray, int x)
{
    ray->camera = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = ray->dir_x + ray->fov_x * ray->camera;
    ray->ray_dir_y = ray->dir_y + ray->fov_y * ray->camera;
    ray->ray_x = (int)cub->pos_x;
    ray->ray_y = (int)cub->pos_y;
    ray.de
}
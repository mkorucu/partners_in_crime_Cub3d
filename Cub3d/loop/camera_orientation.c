#include "../lib/cub3d.h"

void    side_checker(t_cub3d *cub, t_ray *ray, int x)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->posX - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - ray->posX) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->posY - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - ray->posY) * ray->delta_dist_y;
    }
}

void    perform_dda(t_cub3d *cub, t_ray *ray, int x)
{
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x = ray->step_x;
            ray->side = VERTICAL;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y = ray->step_y;
            ray->side = HORIZONTAL; 
        }
        if (cub->map[ray->map_x][ray->map_y] > 0)
            ray->hit = 1;
    }
}
void    camera_orientation(t_cub3d *cub, t_ray *ray, int x)
{
    ray->camera_x = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space. range [-1,1]
    ray->ray_dir_x = ray->dirX + ray->fovX * ray->camera_x;
    ray->ray_dir_y = ray->dirY + ray->fovY * ray->camera_x;
    ray->hit = 0;
    ray->map_x = (int)ray->posX;
    ray->map_y = (int)ray->posY;
    ray->delta_dist_x = (ray->ray_dir_x == 0) ? 1e30 : abs(1/ray->ray_dir_x);
    ray->delta_dist_y = (ray->ray_dir_y == 0) ? 1e30 : abs(1/ray->ray_dir_y);
    side_checker(cub, &ray, x);
    perform_dda(cub, &ray, x);
}
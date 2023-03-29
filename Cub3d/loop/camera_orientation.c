#include "../lib/cub3d.h"

void    side_checker(t_cub3d *cub, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

void    perform_dda(t_cub3d *cub, t_ray *ray)
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
		if (cub->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
	if (ray->side == VERTICAL)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	line_calculator(t_cub3d *cub, t_ray *ray)
{
	ray->line_height =(int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (HEIGHT - ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (HEIGHT + ray->line_height) / 2;
	if (ray->draw_end > HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == VERTICAL && ray->step_x == 1)
		ray->wall_side = 'E';
	else if (ray->side == VERTICAL && ray->step_x == -1)
		ray->wall_side = 'W';
	else if (ray->side == HORIZONTAL && ray->step_y == 1)
		ray->wall_side = 'N';
	else if (ray->side == HORIZONTAL && ray->step_y == -1)
		ray->wall_side = 'S';
}
void    camera_orientation(t_cub3d *cub, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space. ranges [-1,1]
	ray->ray_dir_x = ray->dir_x + ray->fov_x * ray->camera_x; // ışının yönü, 
	ray->ray_dir_y = ray->dir_y + ray->fov_y * ray->camera_x;
	ray->hit = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = (ray->ray_dir_x == 0) ? 1e30 : abs(1/ray->ray_dir_x);
	ray->delta_dist_y = (ray->ray_dir_y == 0) ? 1e30 : abs(1/ray->ray_dir_y);
	side_checker(cub, ray);
	perform_dda(cub, ray);
	line_calculator(cub, ray);
}
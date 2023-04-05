/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:46:15 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:46:16 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	side_checker(t_ray *ray)
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

void	perform_dda(t_cub3d *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = VERTICAL;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = HORIZONTAL;
		}
		if (ray->map_x < 0)
			ray->map_x = 0;
		if (ray->map_y < 0)
			ray->map_y = 0;
		if (cub->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == VERTICAL)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	line_calculator(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (HEIGHT - ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (HEIGHT + ray->line_height) / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == VERTICAL && ray->step_x == 1)
		ray->wall_side = 'E';
	else if (ray->side == VERTICAL && ray->step_x == -1)
		ray->wall_side = 'W';
	else if (ray->side == HORIZONTAL && ray->step_y == 1)
		ray->wall_side = 'S';
	else if (ray->side == HORIZONTAL && ray->step_y == -1)
		ray->wall_side = 'N';
}

void	set_image(t_cub3d *cub, t_ray *ray)
{
	if (ray->side == VERTICAL)
		ray->wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double) cub->t_width);
	if (ray->side == VERTICAL && ray->step_x == 1)
		ray->tex_x = cub->t_width - ray->tex_x - 1;
	else if (ray->side == 1 && ray->step_y == -1)
		ray->tex_x = cub->t_width - ray->tex_x - 1;
	ray->step = 1.0 * cub->t_height / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) \
	* ray->step;
}

void	camera_orientation(t_cub3d *cub, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->fov_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->fov_y * ray->camera_x;
	ray->hit = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	side_checker(ray);
	perform_dda(cub, ray);
	line_calculator(ray);
	set_image(cub, ray);
}

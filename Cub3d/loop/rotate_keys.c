/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:46:21 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:46:22 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	rotation_keys(t_ray *ray, int sign)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(ray->rot_speed * sign) - \
	ray->dir_y * sin(ray->rot_speed * sign);
	ray->dir_y = old_dir_x * sin(ray->rot_speed * sign) + \
	ray->dir_y * cos(ray->rot_speed * sign);
	old_fov_x = ray->fov_x;
	ray->fov_x = ray->fov_x * cos(ray->rot_speed * sign) - \
	ray->fov_y * sin(ray->rot_speed * sign);
	ray->fov_y = old_fov_x * sin(ray->rot_speed * sign) + \
	ray->fov_y * cos(ray->rot_speed * sign);
}

#include "../lib/cub3d.h"

void	press_rot_d_key(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = cub3d->ray.dir_x;
	cub3d->ray.dir_x = cub3d->ray.dir_x * cos(-cub3d->ray.rot_speed) - cub3d->ray.dir_y * sin(-cub3d->ray.rot_speed);
	cub3d->ray.dir_y = old_dir_x * sin(-cub3d->ray.rot_speed) + cub3d->ray.dir_y * cos(-cub3d->ray.rot_speed);
	old_fov_x = cub3d->ray.fov_x;
	cub3d->ray.fov_x = cub3d->ray.fov_x * cos(-cub3d->ray.rot_speed) - cub3d->ray.fov_y * sin(-cub3d->ray.rot_speed);
	cub3d->ray.fov_y = old_fov_x * sin(-cub3d->ray.rot_speed) + cub3d->ray.fov_y * cos(-cub3d->ray.rot_speed);
}

void	press_rot_a_key(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = cub3d->ray.dir_x;
	cub3d->ray.dir_x = cub3d->ray.dir_x * cos(cub3d->ray.rot_speed) - cub3d->ray.dir_y * sin(cub3d->ray.rot_speed);
	cub3d->ray.dir_y = old_dir_x * sin(cub3d->ray.rot_speed) + cub3d->ray.dir_y * cos(cub3d->ray.rot_speed);
	old_fov_x = cub3d->ray.fov_x;
	
	cub3d->ray.fov_x = cub3d->ray.fov_x * cos(cub3d->ray.rot_speed) - cub3d->ray.fov_y * sin(cub3d->ray.rot_speed);
	cub3d->ray.fov_y = old_fov_x * sin(cub3d->ray.rot_speed) + cub3d->ray.fov_y * cos(cub3d->ray.rot_speed);
}
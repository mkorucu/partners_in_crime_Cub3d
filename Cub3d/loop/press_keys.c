#include "../lib/cub3d.h"

void	press_w_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->ray.pos_y)][(int)(cub3d->ray.pos_x + \
	cub3d->ray.dir_x * cub3d->ray.move_speed)] != '1')
		cub3d->ray.pos_x += cub3d->ray.dir_x * cub3d->ray.move_speed;
	if (cub3d->map[(int)(cub3d->ray.pos_y + cub3d->ray.dir_y * \
	cub3d->ray.move_speed)][(int)(cub3d->ray.pos_x)] != '1')
		cub3d->ray.pos_y += cub3d->ray.dir_y * cub3d->ray.move_speed;
}

void	press_s_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->ray.pos_y)][(int)(cub3d->ray.pos_x - \
	cub3d->ray.dir_x * cub3d->ray.move_speed)] != '1')
		cub3d->ray.pos_x -= cub3d->ray.dir_x * cub3d->ray.move_speed;
	if (cub3d->map[(int)(cub3d->ray.pos_y - cub3d->ray.dir_y * \
	cub3d->ray.move_speed)][(int)(cub3d->ray.pos_x)] != '1')
		cub3d->ray.pos_y -= cub3d->ray.dir_y * cub3d->ray.move_speed;
}

void	press_a_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->ray.pos_y)][(int)(cub3d->ray.pos_x - \
	cub3d->ray.fov_x * cub3d->ray.move_speed)] != '1')
		cub3d->ray.pos_x -= cub3d->ray.fov_x * cub3d->ray.move_speed;
	if (cub3d->map[(int)(cub3d->ray.pos_y - cub3d->ray.fov_y * \
	cub3d->ray.move_speed)][(int)(cub3d->ray.pos_x)] != '1')
		cub3d->ray.pos_y -= cub3d->ray.fov_y * cub3d->ray.move_speed;
}

void	press_d_key(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->ray.pos_y)][(int)(cub3d->ray.pos_x + \
	cub3d->ray.fov_x * cub3d->ray.move_speed)] != '1')
		cub3d->ray.pos_x += cub3d->ray.fov_x * cub3d->ray.move_speed;
	if (cub3d->map[(int)(cub3d->ray.pos_y + cub3d->ray.fov_y * \
	cub3d->ray.move_speed)][(int)(cub3d->ray.pos_x)] != '1')
		cub3d->ray.pos_y += cub3d->ray.fov_y * cub3d->ray.move_speed;
}

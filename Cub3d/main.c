#include "lib/cub3d.h"

void print_to_screen(t_cub3d *cub, t_ray *ray, int j, int i)
{
	ray->tex_y = (int)ray->tex_pos & (cub->t_height - 1);
	ray->tex_pos += ray->step;
	if (ray->wall_side == 'N')
		ray->color = cub->walls[0].address[cub->t_height * ray->tex_y + ray->tex_x];
	else if (ray->wall_side == 'S')
		ray->color = cub->walls[1].address[cub->t_height * ray->tex_y + ray->tex_x];
	else if (ray->wall_side == 'E')
		ray->color = cub->walls[2].address[cub->t_height * ray->tex_y + ray->tex_x];
	else if (ray->wall_side == 'W')
		ray->color = cub->walls[3].address[cub->t_height * ray->tex_y + ray->tex_x];
	cub->screen.address[j * WIDTH + i] = ray->color;
}

void	print_map(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		camera_orientation(cub, &cub->ray, i);
		j = cub->ray.draw_start;
		while (j < cub->ray.draw_end)
			print_to_screen(cub, &cub->ray, j++, i);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen.image, 0, 0);
}

int	event_loop(t_cub3d *cub)
{
	setting_ceiling_floor(cub);
	print_map(cub);
	return (0);
}

void	start(t_cub3d *cub, t_file *files)
{
    cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	init_direction_vector(cub);
	init_textures(cub, files, cub->walls, &cub->screen);
    cub->rgb_floor = (files->f.r << 16) + (files->f.g << 8) + files->f.b;
    cub->rgb_ceil = (files->c.r << 16) + (files->c.g << 8) + files->c.b;
	mlx_loop_hook(cub->mlx, &event_loop, cub);
	mlx_hook(cub->mlx_win, 2, 0, &press_key, &cub->keys);
	mlx_hook(cub->mlx_win, 3, 0, &release_key, &cub->keys);
	mlx_hook(cub->mlx_win, 17, 0, &ft_exit, 0);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	if (ac == 2 && !extention_check(av[1]))
	{
		import_map_file(&cub, av[1]);
		checkers(cub);
		start(cub, cub->files);
		free_cub(cub);
	}
	else if (ac != 2)
		errors("argument count mismatch\n");
	else
		perror("extention mismatch\n");
	//system("leaks cub3D");
	return (0);
}
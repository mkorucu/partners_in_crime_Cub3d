#include "lib/cub3d.h"

void	print_map(t_cub3d *cub)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < WIDTH)
	{
		camera_orientation(cub, &cub->ray, x);
		i = cub->ray.draw_start;
		while (i < cub->ray.draw_end)
			print_screen(cub, &cub->ray, ++i, x);
		x++;
	}
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
	cub->screen.image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->screen.address = (int *)mlx_get_data_addr(cub->screen.image, &cub->screen.bpp,&cub->screen.line, &cub->screen.endian);
	init_direction_vector(cub);
	init_textures(cub, files, cub->walls, &cub->screen);
    cub->rgb_floor = (files->f.r << 16) + (files->f.g << 8) + files->f.b;
    cub->rgb_ceil = (files->c.r << 16) + (files->c.g << 8) + files->c.b;
	mlx_loop_hook(cub->mlx, &event_loop, cub);
	mlx_hook(cub->mlx_win, 2, 0, &press_key, &cub->keys);
	mlx_hook(cub->mlx_win, 3, 0, &release_key, &cub->keys);
	mlx_hook(cub->mlx_win, 17, 0, &ft_exit, 0);
	//mlx_loop(cub->mlx);
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
	system("leaks cub3D");
	return (0);
}
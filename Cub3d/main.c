#include "lib/cub3d.h"

void	print_map(t_cub3d *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		camera_pos(cub, x);
		
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
	init_wall_textures(cub, files, cub->walls);
	init_map_textures(cub, &cub->screen);
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
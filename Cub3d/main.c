#include "lib/cub3d.h"

int	loop(t_cub3d *cub)
{
	(void)cub;
	return 0;
}

int	press_key(int	key, t_key *keys)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		keys->w = 1;
	else if (key == 1)
		keys->s = 1;
	else if (key == 0)
		keys->a = 1;
	else if (key == 2)
		keys->d = 1;
	else if (key == 123)
		keys->left = 1;
	else if (key == 124)
		keys->right = 1;
	return (0);
}

int	release_key(int	key, t_key *keys)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		keys->w = 0;
	else if (key == 1)
		keys->s = 0;
	else if (key == 0)
		keys->a = 0;
	else if (key == 2)
		keys->d = 0;
	else if (key == 123)
		keys->left = 0;
	else if (key == 124)
		keys->right = 0;
	return (0);
}

int	ft_exit(void)
{
	exit(1);
	return (1);
}
void	start(t_cub3d *cub, t_file *files)
{
    cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	init_wall_textures(cub, files, cub->walls);
	init_map_textures(cub, &cub->screen, &cub->part_of_map);
    cub->rgb_floor = (files->f.r << 16) + (files->f.g << 8) + files->f.b;
    cub->rgb_ceil = (files->c.r << 16) + (files->c.g << 8) + files->c.b;
	mlx_loop_hook(cub->mlx, &loop, cub);
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
		system("leaks cub3D");
	}
	else if (ac != 2)
		perror("Error\n");
	else
		perror("Error\n");
	return (0);
}
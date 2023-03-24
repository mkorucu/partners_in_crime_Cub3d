#include "lib/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	if (ac == 2 && !extention_check(av[1]))
	{
		import_map_file(&cub, av[1]);
		checkers(cub);
		init_wall_textures(cub, cub->files, cub->walls);
		init_map_textures(cub, &cub->screen, &cub->part_of_map);
		free_cub(cub);
	}
	else if (ac != 2)
		perror("Error\n");
	else
		perror("Error\n");
	return (0);
}
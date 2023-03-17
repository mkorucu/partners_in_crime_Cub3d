#include "../lib/cub3d.h"

void	set_direction(t_cub3d *cub, char **str, int i)
{
	if (!*str)
	{
		*str = ft_strdup(&cub->map_file[i][2]);
		*str = ft_strtrim(*str, " ");
	}
	return ;
}

int	check_directions(t_cub3d *cub)
{
	int	i;

	i = 0;
	while(cub->map_file[i])
	{
		cub->map_file[i] = ft_strtrim(cub->map_file[i], " ");
		if (!ft_strncmp(cub->map_file[i], "EA",2))
			set_direction(cub, &cub->east, i);
		if (!ft_strncmp(cub->map_file[i], "SO",2))
			set_direction(cub, &cub->south, i);
		if (!ft_strncmp(cub->map_file[i], "NO",2))
			set_direction(cub, &cub->north, i);
		if (!ft_strncmp(cub->map_file[i], "WE",2))
			set_direction(cub, &cub->west, i);
		i++;
	}
	return 0;
}

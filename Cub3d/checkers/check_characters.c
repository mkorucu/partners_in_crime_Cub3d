#include "../lib/cub3d.h"

int	check_characters(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map_file[i][0] != '1' && cub->map_file[i][0] != '0')
		i++;
	while (cub->map_file[i])
	{
		j = 0;
		while (cub->map_file[i][j])
		{
			if (j == '1' || j == '0' || j == 'E' || j == 'W' || j == 'S' || j == 'N')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
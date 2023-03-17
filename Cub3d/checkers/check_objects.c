#include "../lib/cub3d.h"
int	check_walls(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < cub->xlen && cub->map[0][i] == '1')
	if (i != cub->xlen)
		return (1);
	while(i < cub->ylen)
	{

	}
}
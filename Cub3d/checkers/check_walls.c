#include "../lib/cub3d.h"
int	check_walls(t_cub3d *cub)
{
	int	i;

	i = 0;
	printf("xlen: %d\nylen: %d\n",cub->xlen, cub->ylen);
	while (i < cub->xlen && cub->map[0][i] == '1')
		i++;
	if (i != cub->xlen)
		return (1);
	printf("i: %d\n",i);
	i = 0;
	while(i < cub->ylen && i == '1')
		i++;
	if (i != cub->ylen)
		return (1);
	printf("i: %d\n",i);
	return (0);
}
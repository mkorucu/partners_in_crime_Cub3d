#include "../lib/cub3d.h"

void	setting_ceiling_floor(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while(i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			cub->screen.address[j * WIDTH + i] = cub->rgb_ceil;
		i++;
	}
	i = 0;
	j = HEIGHT / 2;
	while (i < WIDTH && j < HEIGHT)
	{
		cub->screen.address[j * WIDTH + i] = cub->rgb_floor;
		i++;
		if (i == WIDTH)
		{
			j++;
			i = 0;
		}
	}
}
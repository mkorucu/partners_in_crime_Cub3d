#include "../lib/cub3d.h"

int	checkers(t_cub3d *cub)
{
	if (check_walls(cub))
		return (WALLS_MISMATCH);
	
}
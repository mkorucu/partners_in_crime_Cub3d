#include "../lib/cub3d.h"

int	checkers(t_cub3d *cub)
{
	if (check_directions(cub))
		return (DIRECTION_MISMATCH);
	if (check_walls(cub))
		return (WALLS_MISMATCH);
	if (check_characters(cub))
		return (UNKNOWN_CHARACTER);
	return (0);
}
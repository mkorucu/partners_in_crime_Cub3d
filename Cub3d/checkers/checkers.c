#include "../lib/cub3d.h"

int	checkers(t_cub3d *cub)
{
	if (check_directions(cub->files)) //EA, WE vs yönleri ayıklıyor, 2 kez yazılanlarda ilkini kabul ediyor.
		return (DIRECTION_MISMATCH);
	if (check_rgb(cub->files))
		return (RGB_MISMATCH);
	if (check_characters(cub->files)) //E,W,S,N ve 0-1'leri kontrol ediyor
		return (UNKNOWN_CHARACTER);
	return (0);
}
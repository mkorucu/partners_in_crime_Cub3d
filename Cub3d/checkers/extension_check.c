#include "../lib/cub3d.h"

int	extension_check(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strcmp(&map_name[len - 4], ".cub"))
		return (VALID);
	else
		return (EXTENTION_ERROR);
}

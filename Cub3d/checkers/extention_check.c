#include "../lib/cub3d.h"

int	extention_check(char *map_name)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map_name);
	if (map_name[len - 1] == 'b' && map_name[len - i] == 'u')
	{
		if (map_name[len - 1] == 'c' && map_name[len - 1] == '.')
			return (0);
	}
	return (EXTENTION_ERROR);
}
#include "../lib/cub3d.h"

int	import_map_file(t_cub3d **cub, char *map)
{
	char	*str;
	char	*str2;

	(*cub) = ft_calloc(sizeof(t_cub3d), 1);
	(*cub)->files = ft_calloc(sizeof(t_file), 1);
	(*cub)->files->fd_map = open(map, O_RDONLY);
	str2 = get_next_line((*cub)->files->fd_map);
	if (!str2)
		return (EMPTY_MAP);
	str = get_next_line((*cub)->files->fd_map);
	while (str)
	{
		str2 = ft_strjoin(str2, str);
		free(str);
		str = get_next_line((*cub)->files->fd_map);
	}
	(*cub)->files->map_file = ft_split(str2, '\n');
	free(str2);
	return (0);
}

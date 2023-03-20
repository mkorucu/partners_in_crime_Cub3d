#include "../lib/cub3d.h"

static void	set_direction(t_file *files, char **str, int i,int *check)
{
	if (!*str)
	{
		(*check)++;
		*str = ft_strdup(&files->map_file[i][2]);
		*str = ft_strtrim(*str, " ");
	}
	return ;
}

int	check_directions(t_file *files)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while(files->map_file[i])
	{
		if (ft_strcmp(files->map_file[i], "EA"))
			set_direction(files, &files->east, i, &check);
		if (ft_strcmp(files->map_file[i], "SO"))
			set_direction(files, &files->south, i, &check);
		if (ft_strcmp(files->map_file[i], "NO"))
			set_direction(files, &files->north, i, &check);
		if (ft_strcmp(files->map_file[i], "WE"))
			set_direction(files, &files->west, i, &check);
		i++;
	}
	if (check != 4)
		return (DIRECTION_MISMATCH);
	return 0;
}

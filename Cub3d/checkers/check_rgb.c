#include "../lib/cub3d.h"

static void	set_direction(t_file *files, char **str, int i,int *check)
{
	if (!*str)
	{
		(*check)++;
		*str = ft_strdup(&files->map_file[i][1]);
		*str = ft_strtrim(*str, " ");
	}
	return ;
}

int check_rgb(t_file *files)
{
    int	i;
    int	check;

    i = 0;
    check = 0;
    while(files->map_file[i])
    {
        if (ft_strcmp(files->map_file[i], "F"))
            set_direction(files, &files->rgb_f, i, &check);
        if (ft_strcmp(files->map_file[i], "C"))
            set_direction(files, &files->rgb_c, i, &check);
        i++;
    }
    if (check != 2)
        return (RGB_MISMATCH);
    return 0;
}

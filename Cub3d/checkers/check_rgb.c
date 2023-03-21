#include "../lib/cub3d.h"

static int	check_validity(t_file *files)
{
	char	**f;
	char	**c;
	int		i;

	i = 0;
	f = ft_split(files->rgb_f, ',');
	c = ft_split(files->rgb_c, ',');
	while (f[i] || c[i])
	{
		if (ft_atoi(f[i]) > 255 || ft_atoi(f[i]) < 0 || ft_atoi(c[i]) > 255 || ft_atoi(c[i]) < 0)
			break;
		printf("i: %d\n",i++);
	}
	free_array(f);
	free_array(c);
	if (i != 3)
		return (RGB_MISMATCH);
	return (0);
}

static void	set_direction(t_file *files, char **str, int i,int *check)
{
	if (!*str)
	{
		(*check)++;
		*str = ft_strdup(&files->map_file[i][1]);
		*str = ft_strtrim(*str, " ");
	}
}

int check_rgb(t_file *files)
{
	int     i;
	int     check;
	char    *str;
	i = 0;
	check = 0;
	while(files->map_file[i])
	{
		str = ft_strtrim(ft_strdup(files->map_file[i])," ");
		if (ft_strcmp(str, "F"))
			set_direction(files, &files->rgb_f, i, &check);
		if (ft_strcmp(str, "C"))
			set_direction(files, &files->rgb_c, i, &check);
		i++;
	}
	if (check != 2)
		return (RGB_MISMATCH);
	if (check_validity(files))
		return (RGB_MISMATCH);
	return 0;
}

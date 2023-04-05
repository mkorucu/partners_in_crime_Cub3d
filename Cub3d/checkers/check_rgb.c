#include "../lib/cub3d.h"

int	mini_atoi(char *str)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			sum = 10 * sum + (str[i] - 48);
		else
			break ;
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t')
			i++;
	if (str[i])
		return (-1);
	return (sum);
}

static int	check_validity(char *rgb)
{
	char	**str;
	int		i;

	i = -1;
	str = ft_split(rgb, ',');
	while (str[++i])
		if (mini_atoi(str[i]) > 255 || mini_atoi(str[i]) < 0)
			break ;
	free_array(str);
	if (i != 3)
		return (RGB_MISMATCH);
	return (0);
}

static void	get_color_line(char *line, char **str, int *check)
{
	if (!*str)
	{
		(*check)++;
		*str = ft_strdup(&line[1]);
		*str = ft_strtrim(*str, "\t ");
	}
}

void	get_rgb(char *ceil, char *floor, t_file *files)
{
	char	**color;

	color = ft_split(ceil, ',');
	files->c.r = ft_atoi(color[0]);
	files->c.g = ft_atoi(color[1]);
	files->c.b = ft_atoi(color[2]);
	free_array(color);
	color = ft_split(floor, ',');
	files->f.r = ft_atoi(color[0]);
	files->f.g = ft_atoi(color[1]);
	files->f.b = ft_atoi(color[2]);
	free_array(color);
}

int	check_rgb(t_file *files)
{
	int		i;
	int		check;
	char	*str;

	i = 0;
	check = 0;
	while (files->map_file[i])
	{
		str = ft_strtrim(ft_strdup(files->map_file[i]), "\t ");
		if (ft_strcmp(str, "F"))
			get_color_line(str, &files->rgb_f, &check);
		if (ft_strcmp(str, "C"))
			get_color_line(str, &files->rgb_c, &check);
		i++;
		free(str);
	}
	if (check != 2)
		return (RGB_MISMATCH);
	if (check_validity(files->rgb_f) || check_validity(files->rgb_c))
		return (RGB_MISMATCH);
	get_rgb(files->rgb_c, files->rgb_f, files);
	return (VALID);
}

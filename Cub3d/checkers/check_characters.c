#include "../lib/cub3d.h"


int	compare(char str)
{
	if (str == '1' || str == '0' || str  == 'E' || str == 'W' || str == 'S' || \
	str == 'N' || str == ' ' || str == '\t')
		return (0);
	else
		return (1);
}

static int	eliminator(char **str)
{
	int	i;
	char *curr;

	i = 0;
	while(str[i])
	{
		if (ft_strcmp(str[i], "EA") || ft_strcmp(str[i], "SO") \
		|| ft_strcmp(str[i], "NO") || ft_strcmp(str[i], "WE") \
		|| ft_strcmp(str[i], "F") || ft_strcmp(str[i], "C"))
			i++;
		else
		{
			curr = str[i];
			while (*curr == ' ' || *curr == '\t')
				curr++;
			if (compare(str[i]))
				return (UNKNOWN_CHARACTER);
		}
			return (i);
	}
}
static int	map_line_finder(char **str)
{
	char *curr;
	int	i;

	i = 0;
	while (str[i])
	{
		curr = str[i];
		while (*curr == '\t' || *curr == ' ')
			curr++;
		if (*curr == '1' || *curr == '0')
			return (i);
		i++;
	}
	return (-1);
}

int	check_characters(t_file *files)
{
	int	i;
	int		j;
	char	*x;

	i = map_line_finder(files->map_file);
	if (i == -1)
		return ()
	while (files->map_file[i])
	{
		j = -1;
		while (files->map_file[i][++j])
		{
			if (compare(files->map_file[i][j]))
				return (UNKNOWN_CHARACTER);
		}
		i++;
	}
	return (0);
}
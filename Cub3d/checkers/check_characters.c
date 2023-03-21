#include "../lib/cub3d.h"


static int	compare(char *str)
{
	static int	i;

	while (*str)
	{
		if (*str  == 'E' || *str == 'W' || *str == 'S' || *str == 'N')
			i++;
		else if (*str != '1' && *str != '0' && *str != ' ' && *str != '\t')
			return (UNKNOWN_CHARACTER);
		str++;
	}
	if (i > 1)
		return (UNKNOWN_CHARACTER);
	return (0);
}

int	check_characters(char **str)
{
	int		i;
	char	*curr;
	i = -1;
	while(str[++i])
	{
		curr = ft_strtrim(ft_strdup(str[i]), "\t ");
		if (ft_strcmp(curr, "EA") || ft_strcmp(curr, "SO") \
		|| ft_strcmp(curr, "NO") || ft_strcmp(curr, "WE") \
		|| ft_strcmp(curr, "F") || ft_strcmp(curr, "C"))
			free(curr);
		else if (compare(curr))
		{
			free(curr);
			return (UNKNOWN_CHARACTER);
		}
	}
	return (0);
}
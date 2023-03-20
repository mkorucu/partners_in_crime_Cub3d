#include "../lib/cub3d.h"


static int	compare(char *str)
{
	while (*str)
	{
		if (*str == '1' || *str == '0' || *str  == 'E' || *str == 'W' || \
		*str == 'S' || *str == 'N' || *str == ' ' || *str == '\t')
			str++;
		else
			return (UNKNOWN_CHARACTER);
	}
	return (0);
}

int	check_characters(char **str)
{
	int		i;
	char	*curr;
	int		j;

	i = -1;
	while(str[++i])
	{
		printf("test %d\n",i);
		curr = ft_strtrim(ft_strdup(str[i]), " ");
		if (ft_strcmp(curr, "EA") || ft_strcmp(curr, "SO") \
		|| ft_strcmp(curr, "NO") || ft_strcmp(curr, "WE") \
		|| ft_strcmp(curr, "F") || ft_strcmp(curr, "C"))
			free(curr);
		else
		{
			free(curr);
			j = 0;
			while (str[i][j] == ' ' || str[i][j] == '\t')
				j++;
			if (compare(&str[i][j]))
				return (UNKNOWN_CHARACTER);
		}
	}
	return (0);
}
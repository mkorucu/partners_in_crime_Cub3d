#include "../lib/cub3d.h"


static int	compare(t_cub3d *cub, char **str)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (ft_strchr("WESN", str[i][j]))
			{
				cub->start_direction = str[i][j];
				cub->pos_x = j;
				cub->pos_y = i;
				count++;
				str[i][j] = '0';
			}
			else if (!ft_strchr("10 \t", str[i][j]))
				return (UNKNOWN_CHARACTER);
		}
	}
	if (count != 1)
		return (UNKNOWN_CHARACTER);
	return (0);
}

int	check_characters(char **str, t_cub3d *cub)
{
	int		i;
	char	*curr;

	i = 0;
	curr = ft_strtrim(ft_strdup(*str), "\t ");
	while(ft_strcmp(curr, "EA") || ft_strcmp(curr, "SO") \
		|| ft_strcmp(curr, "NO") || ft_strcmp(curr, "WE") \
		|| ft_strcmp(curr, "F") || ft_strcmp(curr, "C"))
	{
		free(curr);
		i++;
		curr = ft_strtrim(ft_strdup(str[i]), "\t ");
	}
	free(curr);
	if (compare(cub, &cub->files->map_file[i]))
		return (UNKNOWN_CHARACTER);
	return (VALID);
}
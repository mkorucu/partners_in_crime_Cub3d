#include "../lib/cub3d.h"

int	check_wall(t_cub3d *cub, char ch)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (cub->map[i] && cub->map[i + 1])
	{
		s = cub->map[i];
		j = 0;
		while (s[j])
		{
			if (s[j] == ch && ((!j || s[j - 1] == ' '
						|| !s[j + 1] || s[j + 1] == ' ')
					|| ((size_t)j + 1 > ft_strlen(cub->map[i - 1])
						|| cub->map[i - 1][j] == ' ')
				|| ((size_t)j + 1 > ft_strlen(cub->map[i + 1])
					|| cub->map[i + 1][j] == ' ')))
				return (SURROUND_MISMATCH);
			j++;
		}	
		i++;
	}
	if (ft_strchr(cub->map[i], ch) || ft_strchr(cub->map[0], ch))
		return (SURROUND_MISMATCH);
	return (VALID);
}
#include "../lib/cub3d.h"

void	extract_map(t_cub3d *cub)
{
	int		i;
	int		j;
	char	**str;
	char	*curr;

	str = cub->files->map_file;
	i = 5;
	while (str[++i])
	{
		curr = ft_strtrim(ft_strdup(str[i]), "\t ");
		if (curr[0] == '1' || curr[0] == '0')
			break;
		free(curr);
	}
	free(curr);
	j = i;
	while (str[i])
		i++;
	cub->map = ft_calloc(sizeof(char *), i - j + 1);
	cub->map_heigh = i - j + 1;
	i = 0;
	while (str[j])
		cub->map[i++] = ft_strdup(str[j++]);
}

int	checkers(t_cub3d *cub)
{
	if (check_directions(cub->files)) //EA, WE vs yönleri ayıklıyor, 2 kez yazılanlarda ilkini kabul ediyor.
		errors("direction mismatch!\n");
	// if (check_is_open(cub->files))
	// 	return (CANNOT_OPEN);
	if (check_rgb(cub->files))
		errors("rgb mismatch!\n");
	if (check_characters(cub->files->map_file, cub)) //E,W,S,N ve 0-1'leri kontrol ediyor
		errors("unknown character!\n");
	extract_map(cub);
	if (check_wall(cub))
		errors("surround mismatch!\n");
	return (0);
}
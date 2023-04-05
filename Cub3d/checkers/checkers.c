/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:44:48 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:44:49 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			break ;
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
	if (check_directions(cub->files))
		errors("direction mismatch!\n");
	if (check_is_open(cub->files))
		errors("cannot open assets");
	if (check_rgb(cub->files))
		errors("rgb mismatch!\n");
	if (check_characters(cub->files->map_file, cub))
		errors("unknown character!\n");
	extract_map(cub);
	if (check_wall(cub))
		errors("surround mismatch!\n");
	return (0);
}

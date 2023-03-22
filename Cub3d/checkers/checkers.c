/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:01:04 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/22 10:12:38 by mkorucu          ###   ########.fr       */
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
		cub->map[i++] = str[j++];
}

int	checkers(t_cub3d *cub)
{
	if (check_directions(cub->files)) //EA, WE vs yönleri ayıklıyor, 2 kez yazılanlarda ilkini kabul ediyor.
		return (DIRECTION_MISMATCH);
	// if (check_is_open(cub->files))
	// 	return (CANNOT_OPEN);
	if (check_rgb(cub->files))
		return (RGB_MISMATCH);
	if (check_characters(cub->files->map_file, cub)) //E,W,S,N ve 0-1'leri kontrol ediyor
		return (UNKNOWN_CHARACTER);
	extract_map(cub);
	if (check_wall(cub, 'N') || check_wall(cub, 'S') || check_wall(cub, 'E') \
		|| check_wall(cub, 'W') || check_wall(cub, '0'))
		return (SURROUND_MISMATCH);
	return (0);
}
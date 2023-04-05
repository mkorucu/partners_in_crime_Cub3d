/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:44:32 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:44:33 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (ft_strchr("WESN", str[i][j]) && ++count)
			{
				cub->start_direction = str[i][j];
				cub->ray.pos_x = (double)j - 0.01;
				cub->ray.pos_y = (double)i - 0.01;
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
	while (ft_strcmp(curr, "EA") || ft_strcmp(curr, "SO") \
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

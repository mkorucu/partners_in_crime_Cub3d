/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:44:38 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 15:22:09 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

static void	set_direction(char *line, char **str, int *check)
{
	if (!*str)
	{
		(*check)++;
		*str = ft_strdup(&line[2]);
		*str = ft_strtrim(*str, "\t ");
	}
}

int	check_directions(t_file *files)
{
	int		i;
	int		check;
	char	*str;

	i = 0;
	check = 0;
	while (files->map_file[i])
	{
		str = ft_strtrim(ft_strdup(files->map_file[i]), "\t ");
		if (ft_strcmp(str, "EA"))
			set_direction(str, &files->east, &check);
		if (ft_strcmp(str, "SO"))
			set_direction(str, &files->south, &check);
		if (ft_strcmp(str, "NO"))
			set_direction(str, &files->north, &check);
		if (ft_strcmp(str, "WE"))
			set_direction(str, &files->west, &check);
		i++;
		free(str);
	}
	if (check != 4)
		return (DIRECTION_MISMATCH);
	return (VALID);
}

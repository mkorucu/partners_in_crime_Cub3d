/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:44:47 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:44:48 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int	check_wall(t_cub3d *cub)
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
			if (s[j] == '0' && ((!j || s[j - 1] == ' '
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
	if (ft_strchr(cub->map[i], '0') || ft_strchr(cub->map[0], '0'))
		return (SURROUND_MISMATCH);
	return (VALID);
}

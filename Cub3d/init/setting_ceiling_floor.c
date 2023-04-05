/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:45:00 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:45:01 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	setting_ceiling_floor(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			cub->screen.address[j * WIDTH + i] = cub->rgb_ceil;
		i++;
	}
	i = 0;
	j = HEIGHT / 2;
	while (i < WIDTH && j < HEIGHT)
	{
		cub->screen.address[j * WIDTH + i] = cub->rgb_floor;
		i++;
		if (i == WIDTH)
		{
			j++;
			i = 0;
		}
	}
}

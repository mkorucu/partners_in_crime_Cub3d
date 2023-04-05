/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:44:50 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:44:51 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int	extension_check(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strcmp(&map_name[len - 4], ".cub"))
		return (VALID);
	else
		return (EXTENTION_ERROR);
}

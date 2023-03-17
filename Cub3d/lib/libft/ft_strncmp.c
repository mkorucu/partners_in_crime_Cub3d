/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:59:34 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/17 15:59:38 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && len > 0)
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
		len--;
	}
	if (len == 0)
		return (0);
	return (1);
}

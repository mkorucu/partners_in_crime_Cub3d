/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:45:37 by mkorucu           #+#    #+#             */
/*   Updated: 2023/04/05 12:47:01 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	k = 0;
	if (dstsize != 0)
	{
		while (src[k] != '\0' && k < dstsize - 1)
		{
			dest[k] = src[k];
			k++;
		}
		dest[k] = '\0';
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:12 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/17 16:00:30 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char	*kaynak;
	char	*hedef;
	size_t	i;

	kaynak = (char *)dst;
	hedef = (char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		kaynak[i] = hedef[i];
		i++;
	}
	return (kaynak);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:36:47 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:36:49 by hgermiya         ###   ########.fr       */
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
/*
int main()
{
	char src[] = "aysee";
	char dst[] = "ald";

	printf("%s\n", ft_memcpy(dst, src, 3));
	printf("%s\n", memcpy(dst,src,3));
}
*/

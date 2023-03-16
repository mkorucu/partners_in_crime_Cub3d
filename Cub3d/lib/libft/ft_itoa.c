/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:35:12 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:35:14 by hgermiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			len;
	int			len2;
	long int	n2;

	i = 0;
	n2 = n;
	len = nbrlen(n2);
	len2 = nbrlen(n2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (n2 < 0)
	{
		n2 *= -1;
		res[0] = '-';
		i++;
		len--;
	}
	while (i < len2)
		res[i++] = (((n2 / (ft_div(len--)) % 10) + 48));
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main()
{
	int	a = -2456;
	printf("%s", ft_itoa(a));
}*/

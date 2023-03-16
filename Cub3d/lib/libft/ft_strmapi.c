/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:38:24 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:38:25 by hgermiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (s)
	{
		len = ft_strlen(s);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (NULL);
		i = 0;
		while (i < len)
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
/*
char	f(unsigned int a, char b)
{
	unsigned int alpha;
	alpha = a;
	return (b - 32);
}

int main()
{
	char *arr = "eyupguler";
	printf("%s", ft_strmapi(arr, f));
}
*/

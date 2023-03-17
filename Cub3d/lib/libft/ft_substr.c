/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:53 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/17 16:01:57 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;
	size_t	end;

	if (s)
	{
		end = 0;
		size = ft_strlen(s);
		if (start < size)
			end = size - start;
		if (end > len)
			end = len;
		str = (char *)malloc(sizeof(char) * end + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < end)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}

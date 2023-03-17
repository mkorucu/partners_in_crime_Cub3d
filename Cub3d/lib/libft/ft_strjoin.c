/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:58:41 by mkorucu           #+#    #+#             */
/*   Updated: 2023/03/17 16:01:01 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;
	size_t	total_size;

	if (s1)
	{
		total_size = ft_strlen(s1) + ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (total_size + 1));
		if (!dest)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{	
			dest[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			dest[i++] = s2[j++];
		dest[i] = '\0';
		free(s1);
		return (dest);
	}
	return (0);
}

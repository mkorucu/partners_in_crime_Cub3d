/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:38:00 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:38:03 by hgermiya         ###   ########.fr       */
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
/*
int main()
{
	char *s1;
	char *s2;

	s1 = "eyup";
	s2 = "guler";
	printf("%s",ft_strjoin(s1, s2));
}
*/

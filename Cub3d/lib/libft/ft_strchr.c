/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:37:29 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:37:30 by hgermiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == p)
			return ((char *)&s[i]);
		i++;
	}
	if (p == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char s[] = "salih burak";
	printf("%s", ft_strchr(s, 'b'));
}
*/

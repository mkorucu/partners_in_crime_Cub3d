/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:37:56 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:37:57 by hgermiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
}
/*
void	f(unsigned int a, char *b)
{
	int alpha;
	alpha = a;
	int i;
	i = 0;
	while (b[i] != '\0')
	{
		b[i] = b[i] + 1;
		i++;
	}
}

int main()
{
	char arr[] = "eyup";
	ft_striteri(arr, f);
	printf("%s", arr);
}
*/

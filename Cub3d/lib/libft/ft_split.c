/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgermiya <hgermiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:37:25 by hgermiya          #+#    #+#             */
/*   Updated: 2022/11/29 16:37:35 by hgermiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmanycut(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copyit(char *newstr, const char *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		newstr[j] = s[i - len];
		len--;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

static void	*splitit(char **newstr, char const *s, char c, int howmany)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (j < howmany)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			len++;
		}
		newstr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!newstr[j])
			return (NULL);
		copyit(newstr[j], s, i, len);
		j++;
		len = 0;
	}
	newstr[j] = NULL;
	return (newstr[j]);
}

char	**ft_split(char const *s, char c)
{
	int		howmany;
	char	**newstr;

	if (s)
	{
		howmany = howmanycut(s, c);
		newstr = (char **)malloc(sizeof(char *) * (howmany + 1));
		if (!newstr)
			return (NULL);
		splitit(newstr, s, c, howmany);
		return (newstr);
	}
	return (0);
}
/*
int main()
{
	char *s;
	char **a;
	s = "ebrar genc eyup semih ";
	a = ft_split(s, ' ');
	for (size_t i = 0; i < 4; i++)
		printf("%s\n",a[i]);
}
*/

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


char	*ft_strtrim(char *s1, char const *set)
{
	size_t	i;
	int		j;
	size_t	s1_len;
	char	*dest;

	if (s1)
	{
		s1_len = ft_strlen(s1);
		i = 0;
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
			s1_len--;
		dest = (char *)malloc(sizeof(char) * (s1_len - i + 1));
		if (!dest)
			return (NULL);
		j = 0;
		while (i < s1_len)
			dest[j++] = s1[i++];
		dest[j] = '\0';
		free(s1);
		return (dest);
	}
	return (0);
}

int main(void)
{
	char *str = ft_strdup(" \t mehmet \t  \t   ");
	printf("str:%s.\n",str);
	printf("trimmed:%s.\n",ft_strtrim(str, "\t "));

}
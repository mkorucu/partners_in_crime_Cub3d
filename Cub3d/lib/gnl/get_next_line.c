/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:43:26 by bkeklik           #+#    #+#             */
/*   Updated: 2023/04/05 10:58:33 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_create(char *str)
{
	int		i;
	int		j;
	char	*store;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	store = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!store)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		store[j++] = str[i++];
	store[j] = '\0';
	free(str);
	return (store);
}

char	*ft_read_and_create(int fd, char *str)
{
	char	*buff;
	int		rc;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 1;
	while (!ft_strchr(str, '\n') && rc != 0)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
			return (ft_free(buff));
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_and_create(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_create(str);
	return (line);
}

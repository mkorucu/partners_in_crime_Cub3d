#include "lib/cub3d.h"

static int	import_map_file(t_cub3d **cub, char *map)
{
	char	*str;
	char	*str2;
	int		i;

	(*cub) = ft_calloc(sizeof(t_cub3d) , 1);
	(*cub)->files = ft_calloc(sizeof(t_file), 1);
	(*cub)->files->fd_map = open(map, O_RDONLY);
	str2 = get_next_line((*cub)->files->fd_map);
	if (!str2)
		return (EMPTY_MAP);
	i = 1;
	str = get_next_line((*cub)->files->fd_map);
	while (str)
	{
		i++;
		str2 = ft_strjoin(str2, str);
		free(str);
		str = get_next_line((*cub)->files->fd_map);
	}
	(*cub)->files->map_file = ft_split(str2, '\n');
	free(str2);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	if (ac == 2 && !extention_check(av[1]))
	{
		if (import_map_file(&cub, av[1]))
			ft_putstr_fd("Error!\n", 2);
		if (checkers(cub))
			printf("failure\n");
		else
			printf("helal\n");
		free_cub(cub);
	}
	else if (ac != 2)
		perror("wrong number of argument!\n");
	else
		perror("wrong file extention!\n");
	return (0);
}
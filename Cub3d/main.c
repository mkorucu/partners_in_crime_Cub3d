#include "lib/cub3d.h"
void	setup_maze(t_cub3d **cub, char *map)
{
	char	*str;
	char	*str2;
	int		i;

	*cub = ft_calloc(sizeof(t_cub3d) , 1);
	(*cub)->fd = open(map, O_RDONLY);
	printf("%d\n",(*cub)->fd);
	str2 = get_next_line((*cub)->fd);
	if (str2)
		i = 1;
	str = get_next_line((*cub)->fd);
	(*cub)->xlen = ft_strlen(str2);
	while (str)
	{
		i++;
		str2 = ft_strjoin(str2, str);
		free(str);
		str = get_next_line((*cub)->fd);
	}
	(*cub)->ylen = i;
	(*cub)->map = ft_split(str2, '\n');
	free(str2);
}

int	main(int ac, char **av)
{
	if (ac == 2 && !extention_check(av[1]))
	{
		t_cub3d	*cub;

		setup_maze(&cub, av[1]);
		checkers(cub);
	}
	else if (ac != 2)
		perror("wrong number of argument!\n");
	else
		perror("wrong file extention!\n");
}
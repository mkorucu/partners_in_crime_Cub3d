#include "../lib/cub3d.h"

void	errors(char *str)
{
	ft_putstr_fd("Error\n",2);
	ft_putstr_fd(str, 2);
	exit(1);
}
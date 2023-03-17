#include "../lib/cub3d.h"

int	free_array(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[len])
		len++;
	while (i < len)
		free(arr[i]);
	free(arr);
}
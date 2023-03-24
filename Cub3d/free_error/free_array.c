#include "../lib/cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	free_files(t_file *files)
{
	if (files->east)
		free(files->east);
	if (files->south)
		free(files->south);
	if (files->west)
		free(files->west);
	if (files->north)
		free(files->north);
	if(files->rgb_c)
		free(files->rgb_c);
	if (files->rgb_f)
		free(files->rgb_f);
	if (files->map_file)
		free_array(files->map_file);
	free(files);
}

void	free_cub(t_cub3d *cub)
{
	if (cub->files)
		free_files(cub->files);
	if (cub->map)
		free_array(cub->map);
	free(cub);
}
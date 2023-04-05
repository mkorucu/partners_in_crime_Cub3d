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
	if (files->rgb_c)
		free(files->rgb_c);
	if (files->rgb_f)
		free(files->rgb_f);
	if (files->map_file)
		free_array(files->map_file);
	close(files->fd_east);
	close(files->fd_map);
	close(files->fd_north);
	close(files->fd_south);
	close(files->fd_west);
	free(files);
}

void	free_images(t_image *c, t_image *f, t_image *walls, t_image *screen)
{
	int	i;
	
	i = 0;
	if (c->address)
		free(c->address);
	if (c->image)
		free(c->image);
	if (f->address)
		free(f->address);
	if (f->image)
		free(f->image);
	while(walls[i].image)
	{
		if(walls[i].address)
			free(walls[i].address);
		if(walls[i].image)
			free(walls[i].image);
		i++;
	}
	if (screen->address)
		free(screen->address);
	if (screen->image)
		free(screen->image);
}

void	free_cub(t_cub3d *cub)
{
	if (cub->files)
		free_files(cub->files);
	if (cub->map)
		free_array(cub->map);
	free_images(&cub->ceiling, &cub->floor, cub->walls, &cub->screen);
	if (cub->mlx)
		free(cub->mlx);
	if (cub->mlx_win)
		free(cub->mlx_win);
	free(cub);
}

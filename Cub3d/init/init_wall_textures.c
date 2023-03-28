#include "../lib/cub3d.h"

void    init_textures(t_cub3d *cub, t_file *file, t_image *walls, t_image *s)
{
	cub->t_width = 64;
	cub->t_height = 64;
	walls[0].image = mlx_xpm_file_to_image(cub->mlx,
			file->north, &cub->t_width, &cub->t_height);
	walls[1].image = mlx_xpm_file_to_image(cub->mlx,
			file->south, &cub->t_width, &cub->t_height);
	walls[2].image = mlx_xpm_file_to_image(cub->mlx,
			file->east, &cub->t_width, &cub->t_height);
	walls[3].image = mlx_xpm_file_to_image(cub->mlx,
			file->west, &cub->t_width, &cub->t_height);
	if (!cub->walls[0].image || !cub->walls[1].image
		|| !cub->walls[2].image || !cub->walls[3].image)
			errors("image transition error!\n");
	walls[0].address = (int *)mlx_get_data_addr(walls[0].image,
			&walls[0].bpp, &walls[0].line, &walls[0].endian);
	walls[1].address = (int *)mlx_get_data_addr(walls[1].image,
			&walls[1].bpp, &walls[1].line, &walls[1].endian);
	walls[2].address = (int *)mlx_get_data_addr(walls[2].image,
			&walls[2].bpp, &walls[2].line, &walls[2].endian);
	walls[3].address = (int *)mlx_get_data_addr(walls[3].image,
			&walls[3].bpp, &walls[3].line, &walls[3].endian);
	s->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	s->address = (int *)mlx_get_data_addr(s->image, &s->bpp,&s->line, &s->endian);
}

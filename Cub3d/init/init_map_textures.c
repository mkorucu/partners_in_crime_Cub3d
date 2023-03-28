#include "../lib/cub3d.h"

void	init_map_textures(t_cub3d *cub, t_image *s)
{
	s->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	s->address = (int *)mlx_get_data_addr(s->image, &s->bpp,&s->line, &s->endian);
	cub->bg_width = WIDTH;
	cub->bg_height = HEIGHT;
}

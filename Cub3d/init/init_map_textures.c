#include "../lib/cub3d.h"

void	init_map_textures(t_cub3d *cub, t_image *s, t_image *pom)
{
	s->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	s->width = WIDTH;
	s->height = HEIGHT;
	s->address = mlx_get_data_addr(s->image, &s->bpp,&s->line, &s->endian);
	pom->image = mlx_new_image(cub->mlx, 200, 200);
	pom->width = WIDTH;
	pom->height = HEIGHT;
	pom->address = mlx_get_data_addr(pom->image, &pom->bpp, &pom->line, &pom->endian);
}

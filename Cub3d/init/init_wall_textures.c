#include "../lib/cub3d.h"

void    init_wall_textures(t_cub3d *cub, t_file *file, t_image *walls)
{
    cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
    walls[0].image = mlx_xpm_file_to_image(cub->mlx,
            file->north, &walls[0].width, &walls[0].height);
    walls[1].image = mlx_xpm_file_to_image(cub->mlx,
            file->south, &walls[1].width, &walls[1].height);
    walls[2].image = mlx_xpm_file_to_image(cub->mlx,
            file->east, &walls[2].width, &walls[2].height);
    walls[3].image = mlx_xpm_file_to_image(cub->mlx,
            file->west, &walls[3].width, &walls[3].height);
    if (!cub->walls[0].image || !cub->walls[1].image
        || !cub->walls[2].image || !cub->walls[3].image)
    		errors("image transition error!\n");
    walls[0].address = mlx_get_data_addr(walls[0].image,
            &walls[0].bpp, &walls[0].line, &walls[0].endian);
    walls[1].address = mlx_get_data_addr(walls[1].image,
            &walls[1].bpp, &walls[1].line, &walls[1].endian);
    walls[2].address = mlx_get_data_addr(walls[2].image,
            &walls[2].bpp, &walls[2].line, &walls[2].endian);
    walls[3].address = mlx_get_data_addr(walls[3].image,
            &walls[3].bpp, &walls[3].line, &walls[3].endian);
}

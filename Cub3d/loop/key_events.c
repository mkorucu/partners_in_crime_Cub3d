#include "../lib/cub3d.h"

int	ft_exit(void)
{
	exit(1);
	return (1);
}

void	key_direction(t_cub3d *cub)
{
	if (cub->keys.w)
		press_w_key(cub);
	if (cub->keys.s)
		press_s_key(cub);
	if (cub->keys.a)
		press_a_key(cub);
	if (cub->keys.d)
		press_d_key(cub);
	if (cub->keys.right)
		press_rot_a_key(cub);
	if (cub->keys.left)
		press_rot_d_key(cub);
}

int	press_key(int	key, t_key *keys)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		keys->w = 1;
	else if (key == 1)
		keys->s = 1;
	else if (key == 0)
		keys->a = 1;
	else if (key == 2)
		keys->d = 1;
	else if (key == 123)
		keys->left = 1;
	else if (key == 124)
		keys->right = 1;
	return (0);
}

int	release_key(int	key, t_key *keys)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		keys->w = 0;
	else if (key == 1)
		keys->s = 0;
	else if (key == 0)
		keys->a = 0;
	else if (key == 2)
		keys->d = 0;
	else if (key == 123)
		keys->left = 0;
	else if (key == 124)
		keys->right = 0;
	return (0);
}
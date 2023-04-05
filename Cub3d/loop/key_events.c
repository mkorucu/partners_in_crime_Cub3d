#include "../lib/cub3d.h"

int	ft_exit(void)
{
	exit(1);
	return (1);
}

void	key_direction(t_cub3d *cub)
{
	if (cub->keys.w)
		press_direction_keys(cub, &cub->ray, 1, 'w');
	if (cub->keys.s)
		press_direction_keys(cub, &cub->ray, -1, 's');
	if (cub->keys.d)
		press_direction_keys(cub, &cub->ray, 1, 'd');
	if (cub->keys.a)
		press_direction_keys(cub, &cub->ray, -1, 'a');
	if (cub->keys.right)
		rotation_keys(&cub->ray, 1);
	if (cub->keys.left)
		rotation_keys(&cub->ray, -1);
}

int	press_key(int key, t_key *keys)
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

int	release_key(int key, t_key *keys)
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

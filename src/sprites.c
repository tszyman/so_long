/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:39:56 by tomek             #+#    #+#             */
/*   Updated: 2024/10/07 22:25:03 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_idle_sprites(t_so_long *so_long, int *width, int *height)
{
	so_long->sprites[0] = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/wall.xpm", width, height);
	so_long->sprites[1] = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/item_fish.xpm", width, height);
	so_long->sprites[2] = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/item_open.xpm", width, height);
	so_long->sprites[3] = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/gate_close.xpm", width, height);
	so_long->sprites[4] = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/gate_open.xpm", width, height);
	so_long->p->idle_right = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/cat_right.xpm", width, height);
	so_long->p->idle_left = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/cat_left.xpm", width, height);
}

static int	check_sprites_loaded(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < N_SPRITES)
	{
		if (!so_long->sprites[i])
			return (0);
		i++;
	}
	if (!so_long->p->idle_left || !so_long->p->idle_right)
		return (0);
	return (1);
}

int	load_sprites(t_so_long *so_long)
{
	int	width;
	int	height;

	load_idle_sprites(so_long, &width, &height);
	if (!check_sprites_loaded(so_long))
	{
		error_msg(5);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:39:00 by tomek             #+#    #+#             */
/*   Updated: 2024/09/30 22:54:09 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	cleanup_player(t_so_long *so_long)
{
	if (so_long->p)
	{
		free(so_long->p);
		so_long->p = NULL;
	}
}

void	cleanup_display(t_so_long *so_long)
{
	if (so_long->win)
	{
		mlx_destroy_window(so_long->mlx,so_long->win);
		so_long->win = NULL;
	}
	if (so_long->mlx)
	{
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
		so_long->mlx = NULL;
	}
}

void	cleanup_map(t_so_long *so_long)
{
	int	i;

	if (so_long->map)
	{
		i = 0;
		while (i < so_long->h)
		{
			if (so_long->map[i])
			{
				free(so_long->map[i]);
				so_long->map[i] = NULL;
			}
			i++;
		}
		free(so_long->map);
		so_long->map = NULL;
	}
	if (so_long->map_path)
	{
		free(so_long->map_path);
		so_long->map_path = NULL;
	}
}

void	cleanup_all(t_so_long *so_long)
{
	cleanup_map(so_long);
	//cleanup_sprites(so_long);
	cleanup_player(so_long);
	cleanup_display(so_long);
}
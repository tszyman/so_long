/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:36:39 by tomek             #+#    #+#             */
/*   Updated: 2024/09/29 21:57:49 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_so_long_struct(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long)
		return (0);
	so_long->win = NULL;
	so_long->w = 100;
	so_long->h = 100;
	so_long->map_fd = 0;
	so_long->collect_total = 0;
	so_long->game_over = 0;
	so_long->collect_count = 0;
	so_long->exit_found = 0;
	so_long->map_path = NULL;
	so_long->map = NULL;
	so_long->map_copy = NULL;
	so_long->p = ft_calloc(1, sizeof(t_player));
	if (!so_long->p)
		return (0);
	so_long->p->moves = 0;
	so_long->p->is_facing_right = 1;
	return (1);
}

int	init_window(t_so_long *so_long)
{
	int	win_width;
	int	win_height;

	win_width = so_long->w * TILE_SIZE;
	win_height = so_long->h * TILE_SIZE;
	so_long->win = mlx_new_window(so_long->mlx, 
									win_width, 
									win_height, 
									WINDOW_TITLE);
	if(!so_long->win)
		return (0);
	return (1);
}

// int	init_map(t_so_long *so_long, int argc), char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		error_msg(1);
// 		return (0);
// 	}
// 	return (1);
// }
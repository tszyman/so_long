/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:36:39 by tomek             #+#    #+#             */
/*   Updated: 2024/09/30 23:01:33 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_map(t_so_long *so_long)
{
	if (!wall_check(so_long))
		return (0);
	if (!item_check(so_long))
		return (0);
	if (!exit_check(so_long))
		return (0);
	if (!player_check(so_long))
		return (0);
	if (!validate_map(so_long))
		return (0);
	return (1);
}

int	init_so_long_struct(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long)
		return (0);
	so_long->win = NULL;
	so_long->w = 100;
	so_long->h = 100;
	so_long->map_fd = 0;
	so_long->items_total = 0;
	so_long->game_over = 0;
	so_long->item_count = 0;
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

int	init_map(t_so_long *so_long, int argc, char *argv[])
{
	if (argc != 2)
	{
		error_msg(1);
		return (0);
	}
	return (1);
	if (!check_path(argv[1], so_long))
	{
		error_msg(2);
		return (0);
	}
	if (!fill_map(so_long))
	{
		error_msg(3);
		return (0);
	}
	if (!check_map(so_long))
	{
		error_msg(4);
		return(0);
	}
	return (1);
}
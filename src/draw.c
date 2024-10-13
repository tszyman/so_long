/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:34:32 by tomek             #+#    #+#             */
/*   Updated: 2024/10/11 15:40:25 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_walls(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->h)
	{
		x = 0;
		while (x < so_long->w)
		{
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[0], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void	draw_items(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->h)
	{
		x = 0;
		while (x < so_long->w)
		{
			if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[1], x * TILE_SIZE, y * TILE_SIZE);
			else if (so_long->map[y][x] == 'c')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[2], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void	draw_gate(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->h)
	{
		x = 0;
		while (x < so_long->w)
		{
			if (so_long->map[y][x] == 'E')
			{
				if (so_long->items_total == 0)
					mlx_put_image_to_window(so_long->mlx, so_long->win,
						so_long->sprites[4], x * TILE_SIZE, y * TILE_SIZE);
				else
					mlx_put_image_to_window(so_long->mlx, so_long->win,
						so_long->sprites[3], x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

static void	draw_player(t_so_long *so_long)
{
	int		x;
	int		y;
	void	*player_position;

	x = so_long->p->pos[0] * TILE_SIZE;
	y = so_long->p->pos[1] * TILE_SIZE;
	if (so_long->p->is_facing_right)
		player_position = so_long->p->idle_right;
	else
		player_position = so_long->p->idle_left;
	mlx_put_image_to_window(so_long->mlx, so_long->win, player_position, x, y);
}

void	draw_all(t_so_long *so_long)
{
	draw_walls(so_long);
	draw_items(so_long);
	draw_gate(so_long);
	draw_player(so_long);
}

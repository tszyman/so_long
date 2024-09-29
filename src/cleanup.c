/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:39:00 by tomek             #+#    #+#             */
/*   Updated: 2024/09/29 17:46:59 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

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

void	cleanup_all(t_so_long *so_long)
{
	//cleanup_map(so_long);
	//cleanup_sprites(so_long);
	cleanup_player(so_long);
	cleanup_display(so_long);
}
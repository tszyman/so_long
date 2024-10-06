/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:42:04 by tomek             #+#    #+#             */
/*   Updated: 2024/10/06 19:27:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

int	close_hook(t_so_long *so_long)
{
	mlx_loop_end(so_long->mlx);
	return (1);
}

int	keys_hook(int keycode, t_so_long *so_long)
{
	int	new_x_pos;
	int	new_y_pos;

	new_x_pos = so_long->p->pos[0];
	new_y_pos = so_long->p->pos[1];
	if (keycode == 119)
		new_y_pos -= 1;
	else if (keycode == 115)
		new_y_pos += 1;
	else if (keycode == 97)
	{
		new_x_pos -= 1;
		so_long->p->is_facing_right = 0;
	}
	else if (keycode == 100)
	{
		new_x_pos +=1;
		so_long->p->is_facing_right = 1;
	}
	else if (keycode == 65307)
		mlx_loop_end(so_long->mlx);
	player_move(so_long, new_x_pos, new_y_pos);
	return (1);
}

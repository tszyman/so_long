/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:56:30 by tomek             #+#    #+#             */
/*   Updated: 2024/10/06 18:40:56 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

static int	is_move_valid(t_so_long *so_long, int new_x_pos, int new_y_pos)
{
	if (new_x_pos < 0 || new_y_pos < 0 || new_x_pos > so_long->w || new_y_pos > so_long->h)
		return (0);
	if (new_x_pos == so_long->p->pos[0] || new_y_pos == so_long->p->pos[1])
		return (0);
	if (so_long->map[new_x_pos][new_y_pos] == '1')
		return (0);
	return (1);
}

static void	update_player_position(t_so_long *so_long, int new_x_pos, int new_y_pos)
{
	so_long->p->pos[0] = new_x_pos;
	so_long->p->pos[1] = new_y_pos;
	so_long->p->moves++;
	ft_printf("Moves done: %d\n", so_long->p->moves);
}

static void	handle_item(t_so_long *so_long, int new_x_pos, int new_y_pos)
{
	if (so_long->map[new_x_pos][new_y_pos] == 'C')
	{
		so_long->items_total--;
		so_long->map[new_x_pos][new_y_pos] = 'c';
		if (so_long->items_total == 0)
		{
			ft_printf("All items collected! \n");
			ft_printf("Proceed to exit! \n");
		}
		else
			ft_printf("Items to pick: %d \n", so_long->items_total);
	}
}

static void	handle_exit(t_so_long *so_long, int new_x_pos, int new_y_pos)
{
	if (so_long->map[new_x_pos][new_y_pos] == 'E' && so_long->items_total == 0)
	{
		so_long->game_over = 1;
		ft_printf("Game over! Congrats! \n");
		ft_printf("You finished in %d moves \n", so_long->p->moves);
		mlx_loop_end(so_long->mlx);
	}
}

void	player_move(t_so_long *so_long, int new_x_pos, int new_y_pos)
{
	if (!is_move_valid(so_long, new_x_pos, new_y_pos))
		return ;
	update_player_position(so_long, new_x_pos, new_y_pos);
	handle_item(so_long, new_x_pos, new_y_pos);
	handle_exit(so_long, new_x_pos, new_y_pos);
	if (!so_long->game_over)
		draw_all(so_long);
}
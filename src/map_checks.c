/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:28:13 by tomek             #+#    #+#             */
/*   Updated: 2024/10/02 21:25:09 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		player_check(t_so_long *so_long)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				player_count++;
				so_long->p->pos[0] = j;
				so_long->p->pos[1] = i;
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

int		wall_check(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->w)
	{
		if (so_long->map[0][i] != '1'
			|| so_long->map[so_long->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < so_long->h)
	{
		if (so_long->map[i][0] != '1'
			|| so_long->map[i][so_long->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	item_count(t_so_long *so_long)
{
	int	item_count;
	int	i;
	int	j;

	item_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				item_count++;
			j++;
		}
		i++;
	}
	return (item_count);
}

int		item_check(t_so_long *so_long)
{
	int	items;

	items = item_count(so_long);
	if (items < 1)
		return (0);
	so_long->items_total = items;
	return (1);
}

int		exit_check(t_so_long *so_long)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	return (exit_count == 1);
}

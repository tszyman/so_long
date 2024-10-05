/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:17:55 by tomek             #+#    #+#             */
/*   Updated: 2024/10/05 16:02:55 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	initialize_game(t_so_long *so_long, int argc, char *argv[])
{
	if (!init_so_long_struct(so_long))
		return (0);
	//init map
	if (!init_map(so_long, argc, argv))
		{
			cleanup_player(so_long);
			cleanup_display(so_long);
			return (0);
		}
	//init window
	if (!init_window(so_long))
	{
		cleanup_map(so_long);
		cleanup_player(so_long);
		cleanup_display(so_long);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_so_long	so_long;
	
	if (!initialize_game(&so_long, argc, argv))
		exit (EXIT_FAILURE);
	if (!load_sprites(&so_long))
	{
		cleanup(&so_long);
		exit (EXIT_FAILURE); 
	}
	//
	// game launch
	//draw(&so_long);
	//mlx_hook(so_long.win, 17, 0, handle_close, &so_long);
	//mlx_key_hook(so_long.win, key_hook, &so_long);
	//mlx_loop_hool(so_long.mlx, game_loop, &so_long);
	//mlx_loop(so_long.mlx);
	ft_printf("argc: %d\n", argc);
	ft_printf("argv: %s\n", argv[1]);
	cleanup_all(&so_long);
	exit(EXIT_SUCCESS);
}
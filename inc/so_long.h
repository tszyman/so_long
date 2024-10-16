/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:46:38 by tomek             #+#    #+#             */
/*   Updated: 2024/10/11 16:49:57 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define WINDOW_TITLE "so_long"
# define TILE_SIZE 32

# define N_SPRITES 5

typedef struct s_player
{
	int				pos[2];
	int				moves;
	int				is_facing_right;
	void			*idle_right;
	void			*idle_left;
}	t_player;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			map_fd;
	int			items_total;
	int			game_over;
	int			item_count;
	int			exit_found;
	char		*map_path;
	char		**map;
	char		**map_copy;
	void		*sprites[N_SPRITES];
	t_player	*p;
}	t_so_long;

//Initialization
int		init_so_long_struct(t_so_long *so_long);
int		init_window(t_so_long *so_long);
int		init_map(t_so_long *so_long, int argc, char *argv[]);
//static int		check_map(t_so_long *so_long);

//Map initialization
int		check_path(char *path, t_so_long *so_long);
//static int		open_map(t_so_long *so_long, int line_count);
int		fill_map(t_so_long *so_long);

//Map validation
int		validate_map(t_so_long *so_long);

//Map checks
int		wall_check(t_so_long *so_long);
int		item_check(t_so_long *so_long);
int		exit_check(t_so_long *so_long);
int		player_check(t_so_long *so_long);

//Error handling
void	error_msg(int error_nbr);

//Player
void	player_move(t_so_long *so_long, int new_x_pos, int new_y_pos);

//Draw
void	draw_all(t_so_long *so_long);

//Utils
int		count_lines(t_so_long *so_long);

//Hooks
int		close_hook(t_so_long *so_long);
int		keys_hook(int keycode, t_so_long *so_long);

//Sprites
int		load_sprites(t_so_long *so_long);

//Cleanup
void	cleanup_player(t_so_long *so_long);
void	cleanup_display(t_so_long *so_long);
void	cleanup_map(t_so_long *so_long);
void	cleanup_sprites(t_so_long *so_long);
void	cleanup_all(t_so_long *so_long);

#endif

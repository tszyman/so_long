/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:46:38 by tomek             #+#    #+#             */
/*   Updated: 2024/09/29 22:37:16 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
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
	int			collect_total;
	int			game_over;
	int			collect_count;
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

//Map initialization
int		check_path(char *path, t_so_long *so_long);
int		get_map(t_so_long *so_long);

//Checks

//Error handling
void	error_msg(int error_nbr);

//Player

//Map validation


//Cleanup
void	cleanup_player(t_so_long *so_long);
void	cleanup_display(t_so_long *so_long);
void	cleanup_all(t_so_long *so_long);

#endif
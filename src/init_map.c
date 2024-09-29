/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:20:32 by tomek             #+#    #+#             */
/*   Updated: 2024/09/29 22:26:21 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_path(char *path, t_so_long *so_long)
{
	int	path_len;

	path_len = ft_strlen(path);
	if (path_len < 4)
		return (0);
	if (ft_strcmp(&path[path_len - 4], ".ber") != 0)
		return (0);
	so_long->map_path = ft_strdup(path);
	return(1);
}

int	get_map(t_so_long *so_long)
{
	
}
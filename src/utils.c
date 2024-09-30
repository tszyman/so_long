/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:30:32 by tomek             #+#    #+#             */
/*   Updated: 2024/09/30 23:08:07 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_lines(t_so_long *so_long)
{
	char	*line;
	int		count_lines;

	count_lines = 0;
	so_long->map_fd = open(so_long->map_path, O_RDONLY);
	if (so_long->map_fd < 0)
		return (0);
	line = get_next_line(so_long->map_fd);
	while (line != NULL)
	{
		count_lines++;
		free(line);
		line = get_next_line(so_long->map_fd);
	}
	close(so_long->map_fd);
	return (count_lines);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:53:44 by tomek             #+#    #+#             */
/*   Updated: 2024/10/11 15:40:29 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg(int error_nbr)
{
	if (error_nbr == 1)
	{
		ft_printf("Error\n");
		ft_printf("You have to pass only one map!\n");
	}
	if (error_nbr == 2)
	{
		ft_printf("Error\n");
		ft_printf("Something's wrong with the map file!\n");
	}
	if (error_nbr == 3)
	{
		ft_printf("Error\n");
		ft_printf("Something's wrong with map file format!\n");
	}
	if (error_nbr == 4)
	{
		ft_printf("Error\n");
		ft_printf("Something's wrong with the map itself!\n");
	}
	if (error_nbr == 5)
	{
		ft_printf("Error\n");
		ft_printf("Something's wrong with the sprites!\n");
	}
}

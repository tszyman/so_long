/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:41:14 by tomek             #+#    #+#             */
/*   Updated: 2024/03/07 22:08:24 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	if (n != 0)
	{
		while (*s != '\0' && i < (n - 1))
		{
			*dst = *s;
			dst++;
			s++;
			i++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}

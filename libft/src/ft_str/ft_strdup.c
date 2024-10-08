/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:11:16 by tomek             #+#    #+#             */
/*   Updated: 2024/09/30 23:22:15 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*dupl;

	s_len = ft_strlen(s);
	dupl = ft_calloc(s_len + 1, sizeof(char));
	ft_memcpy(dupl, s, s_len + 1);
	return (dupl);
}

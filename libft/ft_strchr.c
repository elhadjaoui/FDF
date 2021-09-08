/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:21:44 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/04 15:36:37 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*h;

	h = (char *)s;
	while (*h)
	{
		if (*h == c)
			return (h);
		h++;
	}
	if (c == '\0')
	{
		return (h);
	}
	return (NULL);
}

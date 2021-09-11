/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:47:35 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 18:44:22 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*p;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(len2 + len1 + 1);
	if (p == NULL)
		return (NULL);
	else
	{
		while (*s1)
			*p++ = *s1++;
		while (*s2)
			*p++ = *s2++;
		*p = '\0';
	}
	p = p - (len2 + len1);
	return (p);
}

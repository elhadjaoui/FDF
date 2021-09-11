/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:34:23 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 16:39:11 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	nuber_of_word(char *s, char c)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (*s)
	{
		i++;
		if (((*(s + 1) != c && *s == c && *(s + 1)
					!= '\0')) || (i == 1 && s[0] != c))
			k++;
		s++;
	}
	return (k);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	closered(void)
{
	exit(0);
}

int	D_XY(int X0, int X1)
{
	return (X1 - X0);
}

void	to_3d(int *p, int *z)
{
	p[0] = (p[0] - p[1]) * cos(.47);
	p[1] = (p[0] + p[1]) * sin(.47) - *z;
}

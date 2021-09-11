/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:54:15 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 12:53:40 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	res;
	int	new;

	res = 0;
	new = 1;
	while (*s)
	{
		if (*s != c && new == 1)
		{
			res++;
			new = 0;
		}
		if (*s == c && new == 0)
			new = 1;
		s++;
	}
	return (res);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_free(char **str)
{
	while (*str != NULL)
	{
		free(*str);
		str++;
	}
	free(str);
}

static void	ft_createword(char **str, const char *src, char c)
{
	char	*word;

	*str = malloc((ft_wordlen(src, c) + 1) * sizeof(char));
	if (*str == 0)
	{
		ft_free(str);
		return ;
	}
	word = *str;
	while (*src && *src != c)
	{
		*word = *src;
		word++;
		src++;
	}
	*word = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**res2;
	int		new;

	res = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	res2 = res;
	new = 0;
	while (*s)
	{
		if (*s != c && new == 0)
		{
			new = 1;
			ft_createword(res, s, c);
			res++;
		}
		if (*s == c && new == 1)
			new = 0;
		s++;
	}
	*res = NULL;
	return (res2);
}

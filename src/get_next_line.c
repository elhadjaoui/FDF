/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:20:26 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 19:17:11 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"
#include "../libft/libft.h"

int	ret(int i, char **buff)
{
	free(*buff);
	if (i != 0)
		return (1);
	return (0);
}

void	norm(char **ptr)
{
	**ptr = '\0';
	(*ptr)++;
}

int	get_next_line(int fd, char **line)
{
	char	*buff;
	char	*ptr;
	char	*tmp;
	int		i;

	ptr = NULL;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	*line = ft_strdup("");
	i = read(fd, buff, BUFFER_SIZE);
	while (!ptr && i)
	{
		buff[i] = '\0';
		ptr = ft_strchr(buff, '\n');
		if (ptr)
			norm(&ptr);
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free (tmp);
		if (!ptr)
			i = read(fd, buff, BUFFER_SIZE);
	}
	return (ret(i, &buff));
}

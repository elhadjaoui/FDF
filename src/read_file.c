/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:49:46 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 19:05:54 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/get_next_line.h"

int	get_map_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = nuber_of_word(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_map_height(char *file_name)
{
	char	*line;
	int		heigth;
	int		fd;

	fd = open(file_name, O_RDONLY);
	heigth = 0;
	while (get_next_line(fd, &line))
	{
		heigth++;
		free(line);
	}
	free(line);
	close(fd);
	return (heigth);
}

t_data	*allocate_map(t_data *dt)
{
	int	i;

	i = 0;
	dt->map = malloc(sizeof(int *) * (dt->heigth));
	while (i < dt->heigth)
	{
		dt->map[i] = malloc(sizeof(int) * (dt->width));
		i++;
	}
	return (dt);
}

void	fill_map(int *list, char *line)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(line, ' ');
	while (numbers[i])
	{
		list[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers[i]);
	free(numbers);
}

void	read_file(t_data *dt, char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	dt->width = get_map_width(file_name);
	dt->heigth = get_map_height(file_name);
	dt = allocate_map(dt);
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		fill_map(dt->map[i], line);
		i++;
		free(line);
	}
	free(line);
}

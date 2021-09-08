/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:49:46 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/07 15:55:04 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/get_next_line.h"

int nuber_of_word(char *s, char c)
{
    int k;
    int i;

    i = 0;
    k = 0;
    while (*s)
    {
        i++;
        if (((*(s + 1) != c && *s == c && *(s + 1) != '\0')) ||
            (i == 1 && s[0] != c))
            k++;
        s++;
    }
    return (k);
}

int get_map_width(char *file_name)
{
    char *line;
    int width;
    int fd;

    fd = open(file_name, O_RDONLY);
    get_next_line(fd, &line);
    width = nuber_of_word(line, ' ');
    free(line);
    close(fd);
    return (width);
}

int get_map_height(char *file_name)
{
    char *line;
    int heigth;
    int fd;

    fd = open(file_name, O_RDONLY);
    heigth = 0;
    while (get_next_line(fd, &line))
    {
        heigth++;
        free(line);
    }
    close(fd);
    return (heigth);
}
t_data *allocate_map(t_data *dt)
{
    int i;

    i = 0;
    dt->map = malloc(sizeof(int *) * (dt->heigth + 1));
    while (i <= dt->heigth)
    {
        dt->map[i] = malloc(sizeof(int) * (dt->width + 1));
        i++;
    }
    return (dt);
}
void fill_map(int *list, char *line)
{
    char **numbers;
    int i;

    i = 0;
    numbers = ft_split(line, ' ');
    while (numbers[i])
    {
        list[i] = ft_atoi(numbers[i]);
        free(numbers[i]);
        i++;
    }
}

void read_file(t_data *dt, char *file_name)
{
    char *line;
    int i;
    int fd;

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
    dt->map[i] = NULL;
}
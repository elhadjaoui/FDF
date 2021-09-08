/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:25:49 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/08 18:18:10 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../minilibx_mms/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_data
{
	int width;
	int heigth ;
	int zoom;
	int color;
	int translate_x;
	int translate_y;
	double angle;
	int **map;
	void *mlx_ptr;
	void *mlx_win;
	void *img_ptr;
	char *img_data;
	int bits_per_pixel;
	int line_length;
	int endian;

} t_data;

void print_error(void);
void ft_putstr_fd(char *s, int fd);
void		read_file(t_data *dt, char *file_name);
void DDA(int X0, int Y0, int X1, int Y1, t_data *dt);
void bresenham(int x1, int y1, int x2, int y2, t_data *dt);
void draw(t_data *dt);
#endif
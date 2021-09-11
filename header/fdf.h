/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:25:49 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 16:26:20 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_mms/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		width;
	int		heigth;
	int		zoom;
	int		color;
	int		translate_x;
	int		translate_y;
	int		z;
	double	angle;
	int		**map;
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

void	print_error(void);
void	ft_putstr_fd(char *s, int fd);
void	read_file(t_data *dt, char *file_name);
void	DDA(int *p1, int *p2, t_data *dt);
void	draw(t_data *dt);
int		closered(void);
int		D_XY(int X0, int X1);
void	zoom(int *p1, int *p2);
void	to_3d(int *p, int *z);
void	increase_height(int *pa, int x1, int y1, t_data *dt);
int		nuber_of_word(char *s, char c);
void	put_pixel(int *p1, int *p2, t_data *dt, int color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:38:37 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 16:41:34 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../minilibx_mms/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../header/fdf.h"

void	DDA_bonus(int *p1, int *p2, t_data *dt);
void	draw_bonus(t_data *dt);
void	zoom_bonus(t_data *dt, int *p1, int *p2);
int		get_color_bonus(int *Z, t_data *dt);
void	increase_height_bonus(int *pa, int x1, int y1, t_data *dt);
void	put_pixel_bonus(int *p1, int *p2, t_data *dt, int color);

#endif
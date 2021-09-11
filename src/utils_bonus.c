/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:46:58 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 17:54:06 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

void	increase_height_bonus(int *pa, int x1, int y1, t_data *dt)
{
	int	p2[2];
	int	p1[2];

	p1[0] = pa[0];
	p1[1] = pa[1];
	p2[0] = x1;
	p2[1] = y1;
	DDA_bonus(p1, p2, dt);
}

void	put_pixel_bonus(int *p1, int *p2, t_data *dt, int color)
{
	float	X;
	float	Y;
	int		steps;
	int		i;

	i = 0;
	if (abs(D_XY(p1[0], p2[0])) > abs(D_XY(p1[1], p2[1])))
		steps = abs(D_XY(p1[0], p2[0]));
	else
		steps = abs(D_XY(p1[1], p2[1]));
	X = p1[0];
	Y = p1[1];
	while (i <= steps)
	{
		mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, round(X) + 600,
					  round(Y) + 600, color);
		X += D_XY(p1[0], p2[0]) / (float)steps;
		Y += D_XY(p1[1], p2[1]) / (float)steps;
		i++;
	}
}

int	get_color_bonus(int *Z, t_data *dt)
{
	if (Z[0] > 0 || Z[1] > 0)
	{
		Z[0] *= dt->z;
		Z[1] *= dt->z;
		return (dt->color);
	}
	else
		return (0xffffff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:24:06 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 16:37:10 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

void	zoom_bonus(t_data *dt, int *p1, int *p2)
{
	p1[0] *= dt->zoom;
	p1[1] *= dt->zoom;
	p2[0] *= dt->zoom;
	p2[1] *= dt->zoom;
}
//******************ROTATE ABOUT X-AXIS************************
// *x = *x;
// *y = (*y * cos(dt->angle)) - (*z * sin(dt->angle));
// *z = (*y1 * sin(dt->angle)) + (*z * cos(dt->angle));

// *x1 = *x1;
// *y1 = (*y1 * cos(dt->angle)) - (*z1 * sin(dt->angle));
// *z1 = (*y1 * sin(dt->angle)) + (*z1 * cos(dt->angle));
//******************ROTATE ABOUT Z-AXIS************************
// *z = *z;
// *x = (*x * cos(dt->angle)) - (*y * sin(dt->angle));
// *y = (*x * sin(dt->angle)) + (*y * cos(dt->angle));

// *z1 = *z1;
// *x1 = (*x1 * cos(dt->angle)) - (*y1 * sin(dt->angle));
// *y1 = (*x1 * sin(dt->angle)) + (*y1 * cos(dt->angle));
//******************ROTATE ABOUT Y-AXIS************************

void	rotation_bonus(t_data *dt, int *p1, int *p2, int *z)
{
	p1[1] = p1[1];
	p1[0] = (z[0] * sin(dt->angle)) + (p1[0] * cos(dt->angle));
	z[0] = (z[0] * cos(dt->angle)) - (p1[0] * sin(dt->angle));
	p2[1] = p2[1];
	p2[0] = (z[1] * sin(dt->angle)) + (p2[0] * cos(dt->angle));
	z[1] = (z[1] * cos(dt->angle)) - (p2[0] * sin(dt->angle));
}

void	translate_bonus(t_data *dt, int *p1, int *p2)
{
	p1[0] += dt->translate_x;
	p1[1] += dt->translate_y;
	p2[0] += dt->translate_x;
	p2[1] += dt->translate_y;
}

void	DDA_bonus(int *pa, int *pb, t_data *dt)
{
	int	Z[2];
	int	p1[2];
	int	p2[2];
	int	color;	

	p1[0] = pa[0];
	p1[1] = pa[1];
	p2[0] = pb[0];
	p2[1] = pb[1];
	Z[0] = dt->map[p1[1]][p1[0]];
	Z[1] = dt->map[p2[1]][p2[0]];
	color = get_color_bonus(Z, dt);
	zoom_bonus(dt, p1, p2);
	to_3d(p1, &Z[0]);
	to_3d(p2, &Z[1]);
	translate_bonus(dt, p1, p2);
	rotation_bonus(dt, p1, p2, Z);
	put_pixel_bonus(p1, p2, dt, color);
}

void	draw_bonus(t_data *dt)
{
	int	x;
	int	y;
	int	p1[2];
	int	p2[2];

	y = 0;
	while (y < dt->heigth)
	{
		x = 0;
		while (x < dt->width)
		{
			p1[0] = x;
			p1[1] = y;
			if (x < dt->width - 1)
			{
				p2[0] = x + 1;
				p2[1] = y;
				DDA_bonus(p1, p2, dt);
			}
			if (y < dt->heigth - 1)
				increase_height_bonus(p1, x, y + 1, dt);
			x++;
		}
		y++;
	}
}

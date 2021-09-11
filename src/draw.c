/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:23:14 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 19:21:07 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	get_color(int *Z, t_data *dt)
{
	if (Z[0] != 0 || Z[1] != 0)
		return (dt->color);
	else
		return (0xffffff);
}

void	put_pixel(int *p1, int *p2, t_data *dt, int color)
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
		mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, round(X) + 500,
					  round(Y) + 500, color);
		X += D_XY(p1[0], p2[0]) / (float)steps;
		Y += D_XY(p1[1], p2[1]) / (float)steps;
		i++;
	}
}

void	DDA(int *pa, int *pb, t_data *dt)
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
	color = get_color(Z, dt);
	zoom(p1, p2);
	to_3d(p1, &Z[0]);
	to_3d(p2, &Z[1]);
	put_pixel(p1, p2, dt, color);
}

void	draw(t_data *dt)
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
				DDA(p1, p2, dt);
			}
			if (y < dt->heigth - 1)
				increase_height(p1, x, y + 1, dt);
			x++;
		}
		y++;
	}
}

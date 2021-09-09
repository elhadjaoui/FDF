/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:23:14 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/09 19:05:38 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void to_3d(int *x, int *y, int *z)
{
   *x = (*x - *y) * cos(.47);
   *y = (*x + *y) * sin(.47) - *z;
}

void zoom(t_data *dt, int *x, int *y, int *x1, int *y1)
{
   *x *= dt->zoom;
   *y *= dt->zoom;
   *x1 *= dt->zoom;
   *y1 *= dt->zoom;
}
void rotation(t_data *dt, int *x, int *y, int *x1, int *y1)
{
   *x = (*x * cos(dt->angle)) - (*y * sin(dt->angle));
   *y =  (*x * sin(dt->angle)) + (*y * cos(dt->angle));
   *x1 = (*x1 * cos(dt->angle)) - (*y1 * sin(dt->angle));
   *y1 =  (*x1 * sin(dt->angle)) + (*y1 * cos(dt->angle));
}
void translate(t_data *dt, int *x, int *y, int *x1, int *y1)
{
   *x += dt->translate_x;
   *y += dt->translate_y;
   *x1 += dt->translate_x;
   *y1 += dt->translate_y;
}

void DDA(int X0, int Y0, int X1, int Y1, t_data *dt)
{
   int steps;
   int dx;
   int dy;
   int z;
   int z1;
   int color;

   z = dt->map[Y0][X0];
   z1 = dt->map[Y1][X1];

   if (z != 0 || z1 != 0)
   {
     color =  dt->color ;
      z *= dt->z;
      z1 *= dt->z;
   }
   else
      color = 0xffffff;
   zoom(dt, &X0, &Y0, &X1, &Y1);
   to_3d(&X0, &Y0, &z);
   to_3d(&X1, &Y1, &z1);
   translate(dt, &X0, &Y0, &X1, &Y1);
   rotation(dt, &X0, &Y0, &X1, &Y1);
   dx = X1 - X0;
   dy = Y1 - Y0;
   if (abs(dx) > abs(dy))
      steps = abs(dx);
   else
      steps = abs(dy);

   float Xinc = dx / (float)steps;
   float Yinc = dy / (float)steps;
   float X = X0;
   float Y = Y0;
   for (int i = 0; i <= steps; i++)
   {
      mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, round(X) + 300, round(Y) + 300, color);
      X += Xinc;
      Y += Yinc;
   }
}

void draw(t_data *dt)
{
   int x;
   int y;

   y = 0;
   while (y < dt->heigth)
   {
      x = 0;
      while (x < dt->width)
      {
         if (x < dt->width - 1)
            DDA(x, y, x + 1, y, dt);
         if (y < dt->heigth - 1)
            DDA(x, y, x, y + 1, dt);
         x++;
      }
      y++;
   }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:23:14 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/10 17:18:37 by mel-hadj         ###   ########.fr       */
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

void rotation(t_data *dt, int *x, int *y, int *x1, int *y1, int *z, int *z1)
{

   *y = *y;
   *x = (*z * sin(dt->angle)) + (*x * cos(dt->angle));
   *z = (*z * cos(dt->angle)) - (*x * sin(dt->angle));

   *y1 = *y1;
   *x1 = (*z1 * sin(dt->angle)) + (*x1 * cos(dt->angle));
   *z1 = (*z1 * cos(dt->angle)) - (*x1 * sin(dt->angle));

   // *z = *z;
   // *x = (*x * cos(dt->angle)) - (*y * sin(dt->angle));
   // *y = (*x * sin(dt->angle)) + (*y * cos(dt->angle));

   // *z1 = *z1;
   // *x1 = (*x1 * cos(dt->angle)) - (*y1 * sin(dt->angle));
   // *y1 = (*x1 * sin(dt->angle)) + (*y1 * cos(dt->angle));
}
void translate(t_data *dt, int *x, int *y, int *x1, int *y1)
{
   *x += dt->translate_x;
   *y += dt->translate_y;
   *x1 += dt->translate_x;
   *y1 += dt->translate_y;
}
int D_XY(int X0, int X1)
{
   return (X1 - X0);
}

int get_color(int *Z, t_data *dt)
{
   if (Z[0] != 0 || Z[1] != 0)
   {
      Z[0] *= dt->z;
      Z[1] *= dt->z;
      return (dt->color);
   }
   else
      return (0xffffff);
}

void DDA(int X0, int Y0, int X1, int Y1, t_data *dt)
{
   int steps;
   int Z[2];
   int color;
   float X;
   float Y;
   int i;

   Z[0] = dt->map[Y0][X0];
   Z[1] = dt->map[Y1][X1];
   i = 0;
   //  if (Z[0] != 0 || Z[1] != 0)
   // {
   //    color = dt->color;
   //    Z[0] *= dt->z;
   //    Z[1] *= dt->z;
   // }
   // else
   //    color = 0xffffff;
   color = get_color(Z, dt);
   zoom(dt, &X0, &Y0, &X1, &Y1);
   to_3d(&X0, &Y0, &Z[0]);
   to_3d(&X1, &Y1, &Z[1]);
   translate(dt, &X0, &Y0, &X1, &Y1);
   rotation(dt, &X0, &Y0, &X1, &Y1, &Z[0], &Z[1]);
   if (abs(D_XY(X0, X1)) > abs(D_XY(Y0, Y1)))
      steps = abs(D_XY(X0, X1));
   else
      steps = abs(D_XY(Y0, Y1));

   X = X0;
   Y = Y0;
   while (i <= steps)
   {
      mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, round(X) + 600, round(Y) + 600, color);
      X += D_XY(X0, X1) / (float)steps;
      Y += D_XY(Y0, Y1) / (float)steps;
      i++;
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

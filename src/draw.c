/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:23:14 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/08 18:21:43 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void to_3d(int *x, int *y, int *z, t_data *dt)
{
   *x = (*x - *y) * cos(dt->angle);
   *y = (*x + *y) * sin(dt->angle) - *z;
}

void zoom(t_data *dt, int *x, int *y, int *x1, int *y1)
{
   *x *= dt->zoom;
   *y *= dt->zoom;
   *x1 *= dt->zoom;
   *y1 *= dt->zoom;
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

   // translate(dt, &X0, &Y0, &X1, &Y1);
   z = dt->map[Y0][X0];
   z1 = dt->map[Y1][X1];
   zoom(dt, &X0, &Y0, &X1, &Y1);

   if (z != 0 || z1 != 0)
      dt->color = 0x006699;
   else
      dt->color = 0xffffff;
   to_3d(&X0, &Y0, &z, dt);
   to_3d(&X1, &Y1, &z1, dt);
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
      mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, round(X) + 300, round(Y) + 300, dt->color);
      X += Xinc;
      Y += Yinc;
   }
}
// int desicion_parameter(int x1, int y1, int x2, int y2)
// {
//    return (2 * (y2 - y1) - (x2 - x1));
// }

// void bresenham(int x1, int y1, int x2, int y2, t_data *dt)
// {
//    int m_new;

//    x1 *= dt->zoom;
//    y1 *= dt->zoom;
//    x2 *= dt->zoom;
//    y2 *= dt->zoom;
//    m_new = desicion_parameter(x1, y1, x2, y2);
//    for (int x = x1, y = y1; x <= x2; x++)
//    {
//       if (m_new > 0)
//       {
//          y++;
//          m_new = m_new + desicion_parameter(x, y, x2, y2);
//       }
//       else
//            m_new = m_new + (2 * (y2 - y));

//       mlx_pixel_put(dt->mlx_ptr, dt->mlx_win, x, y, 0xffffff);
//    }
// }

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

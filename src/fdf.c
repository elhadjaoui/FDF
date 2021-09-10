/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:25:40 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/06 11:32:49 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"



void initialize_color(int *color)
{
	color[0] = 0x00ffff;
	color[1] = 0x990000;
	color[2] = 0x99cc99;
	color[3] = 0xcc3333;
	color[4] = 0xfea0b7;
	color[5] = 0xff9933;
	color[6] = 0xff99cc;
}

int handler(int button, int x, int y, t_data *param)
{
	if (button == 5)
		param->angle += .07;
	if (button == 4)
		param->angle -= .07;
	if (button == 1)
		param->z += 3;
	if (button == 2)
		param->z -= 3;
	x = 0;
	y = 0;
	mlx_clear_window(param->mlx_ptr, param->mlx_win);
	draw(param);
	return 1;
}

void other_keys(t_data *dt, int key)
{
	if (key == 126)
		dt->translate_y -= 10;
	if (key == 124)
		dt->translate_x += 10;
	if (key == 123)
		dt->translate_x -= 10;
	if (key == 125)
		dt->translate_y += 10;
	if (key == 69)
		dt->zoom += 4;
}
int delay_key(int key, t_data *dt)
{
	int *color;
	static int i;

	color = malloc(sizeof(int) * 7);
	initialize_color(color);
	dt->color = color[0];
	if (key == 53)
		exit(EXIT_SUCCESS);
	other_keys(dt, key);
	if (key == 78)
		dt->zoom -= 4;
	if (key == 49)
	{
		if (i < 7)
			dt->color = color[i++];
		else
			i = 0;
	}
	free(color);
	mlx_clear_window(dt->mlx_ptr, dt->mlx_win);
	draw(dt);
	return (key);
}

int closered(void)
{
	exit(0);
}
int main(int ac, char **av)
{
	t_data *dt;

	if (ac == 2)
	{
		dt = malloc(sizeof(t_data));
		dt->mlx_ptr = mlx_init();
		dt->mlx_win = mlx_new_window(dt->mlx_ptr, 1800, 1800, "FDF");
		dt->zoom = 20;
		dt->angle = 0;
		dt->color = 0xeffffff;
		dt->z = 1;
		dt->translate_x = 18;
		dt->translate_y = 18;
		read_file(dt, av[1]);
		draw(dt);
		mlx_key_hook(dt->mlx_win, delay_key, dt);
		mlx_hook(dt->mlx_win, 17, (1L << 17), closered, NULL);
		mlx_mouse_hook(dt->mlx_win, handler, dt);
		mlx_loop(dt->mlx_ptr);
	}
	else
		print_error();
}
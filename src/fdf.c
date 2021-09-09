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

int handler(int button, int x, int y, t_data *param)
{
	if (button == 5)
		param->z += 3;
	if (button == 4)
		param->z -= 3;
	if (button == 1)
		param->angle += .03;
	if (button == 2)
		param->angle -= .03;
	x = 0;
	y = 0;
	mlx_clear_window(param->mlx_ptr, param->mlx_win);
	draw(param);
	return 1;
}
int delay_key(int key, t_data *dt)
{
	t_color color;
	int i;

	
	i = 0;
	color = Cyan;
	if (key == 53)
		exit(EXIT_SUCCESS);
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
	if (key == 78)
		dt->zoom -= 4;
	if (key == 49)
	{
		if (color <= Calamime)
			dt->color = color;
		color++;
	}
	printf("%d\n",key);
	
	// // mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
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
		dt->z = 1;
		dt->translate_x = 18;
		dt->translate_y = 18;
		read_file(dt, av[1]);
		draw(dt);
		// dt->img_ptr = mlx_new_image(dt->mlx_ptr, dt->width, dt->heigth);
		// dt->img_data = mlx_get_data_addr(dt->img_ptr, &dt->bits_per_pixel,
		// 								 &dt->line_length, &dt->endian);
		// if (ac == 3)
		// 	check_save(av[2], dt);
		// mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
		mlx_key_hook(dt->mlx_win, delay_key, dt);
		mlx_hook(dt->mlx_win, 17, (1L << 17), closered, NULL);
		mlx_mouse_hook(dt->mlx_win, handler, dt);
		mlx_loop(dt->mlx_ptr);
	}
	else
		print_error();
}
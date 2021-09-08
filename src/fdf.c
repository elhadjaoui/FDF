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

int delay_key(int key, t_data *dt)
{
	dt->zoom = 10;
	if (key == 53)
		exit(EXIT_SUCCESS);
	// if (key == 49)
	// {

	// }
	// ft_draw(dt);
	// mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
	return (key);
}

int closered(void)
{
	exit(0);
}
int main(int ac, char **av)
{
	t_data *dt;

	if (ac == 2 || ac == 3)
	{
		dt = malloc(sizeof(t_data));
		dt->mlx_ptr = mlx_init();
		dt->mlx_win = mlx_new_window(dt->mlx_ptr, 1800, 1800, "FDF");
		dt->zoom = 20;
		dt->angle = 0.8;
		read_file(dt, av[1]);
		draw(dt);
		// dt->img_ptr = mlx_new_image(dt->mlx_ptr, dt->width, dt->heigth);
		// dt->img_data = mlx_get_data_addr(dt->img_ptr, &dt->bits_per_pixel,
		// 								 &dt->line_length, &dt->endian);
		// if (ac == 3)
		// 	check_save(av[2], dt);
		// mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
		printf("heigth = %d\n", dt->heigth);
		printf("width = %d\n", dt->width);
		mlx_key_hook(dt->mlx_win, delay_key, dt);
		mlx_hook(dt->mlx_win, 17, (1L << 17), closered, NULL);
		mlx_loop(dt->mlx_ptr);
	}
	else
		print_error();
}
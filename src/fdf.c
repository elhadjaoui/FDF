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

int	delay_key(int key, t_data *dt)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 78)
		dt->zoom -= 4;
	return (key);
}

int	main(int ac, char **av)
{
	t_data	*dt;

	if (ac == 2)
	{
		dt = malloc(sizeof(t_data));
		dt->mlx_ptr = mlx_init();
		dt->mlx_win = mlx_new_window(dt->mlx_ptr, 1100, 1100, "FDF");
		dt->color = 0xff9933;
		if (open(av[1], O_RDONLY) == -1)
			exit(-1);
		read_file(dt, av[1]);
		draw(dt);
		mlx_key_hook(dt->mlx_win, delay_key, dt);
		mlx_hook(dt->mlx_win, 17, (1L << 17), closered, NULL);
		mlx_loop(dt->mlx_ptr);
	}
	else
		print_error();
}

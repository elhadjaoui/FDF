/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:48:36 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/11 15:29:19 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("more/fewer arguments than expected\n", 2);
	exit(-1);
}

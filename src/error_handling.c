/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:42:13 by zombunga          #+#    #+#             */
/*   Updated: 2024/11/02 05:12:49 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(void)
{
	write(2, "\033[31mError\n\033[0m", 16);
	write(2, "\033[32m./fractol \033[1;32mmandelbrot\033[0m", 37);
	write(2,
		"\n\033[32m./fractol \033[1;32mjulia <x> <y\033[3mi\033[32m>\033[0m\n", 52);
	exit(1);
}

void	ft_malloc_error(void)
{
	write(2, "Problems with malloc\n", 21);
	exit(1);
}

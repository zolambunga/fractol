/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:42:13 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/31 07:04:48 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(void)
{
	write(2, "\"./fractol \033[4mmandelbrot\033[0m\"\n", 32);
	write(2, "./fractol \033[4mjulia <x> <y\033[3mi\033[4m>\033[0m\n", 42);
	exit(1);
}

void	malloc_error(void)
{
	write(2, "Problems with malloc\n", 21);
	exit(1);
}

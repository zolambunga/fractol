/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:29:31 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/31 16:33:35 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(double unscaled_num, t_scale scale)
{
	return ((scale.new_max - scale.new_min) * (unscaled_num - scale.old_min)
		/ (scale.old_max - scale.old_min) + scale.new_min);
}

t_scale	ft_set_scale(int new_min, int new_max, int old_min, int old_max)
{
	t_scale	scale;

	scale.new_max = new_max;
	scale.new_min = new_min;
	scale.old_max = old_max;
	scale.old_min = old_min;
	return (scale);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:23:27 by zombunga          #+#    #+#             */
/*   Updated: 2024/11/02 11:43:19 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	ft_color_gradient(int iteration, int max_iterations)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)iteration / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

static void	ft_mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	ft_handle_pixel(int x, int y, t_fractal *fractal, int i)
{
	int			color;
	t_scale		scalex;
	t_scale		scaley;
	t_complex	z;
	t_complex	c;

	scalex = ft_set_scale(-2, 2, 0, WIDTH);
	scaley = ft_set_scale(2, -2, 0, HEIGHT);
	z.x = (ft_map(x, scalex) * fractal->zoom) + fractal->shift_x;
	z.y = (ft_map(y, scaley) * fractal->zoom) + fractal->shift_y;
	ft_mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_defintion)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_color_gradient(i, fractal->iterations_defintion);
			ft_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	ft_pixel_put(x, y, &fractal->img, BLACK);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, fractal, 0);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

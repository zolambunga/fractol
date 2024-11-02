/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:58 by zombunga          #+#    #+#             */
/*   Updated: 2024/11/02 04:42:57 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(1);
}

int	ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_KP_Add)
		fractal->iterations_defintion += 10;
	else if (keysym == XK_KP_Subtract)
		fractal->iterations_defintion -= 10;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	(void)x;
	(void)y;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_julia_track(int x, int y, t_fractal *fractal)
{
	t_scale	scalex;
	t_scale	scaley;

	scalex = ft_set_scale(-2, 2, 0, WIDTH);
	scaley = ft_set_scale(2, -2, 0, HEIGHT);
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (ft_map(x, scalex) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (ft_map(y, scaley) * fractal->zoom)
			+ fractal->shift_y;
		ft_fractal_render(fractal);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:02:21 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/31 16:29:41 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	int		iterations_defintion;
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_img	img;
}			t_fractal;

typedef struct s_scale
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}			t_scale;

int			close_handler(t_fractal *fractal);
int			ft_isvalid(char **av, int i, int j);
int			ft_strncmp(char *s1, char *s2, int n);
int			key_handler(int keysym, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

void		ft_error(void);
void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

double		atodbl(char *s);
double		map(double unscaled_num, t_scale scale);

t_scale		ft_set_scale(int new_min, int new_max, int old_min, int old_max);

t_complex	sum_complex(t_complex z, t_complex c);
t_complex	square_complex(t_complex z);

#endif
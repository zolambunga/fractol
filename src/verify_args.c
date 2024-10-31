/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 06:56:37 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/31 14:22:00 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_issign(char sign)
{
	return (sign == '+' || sign == '-');
}

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static int	ft_iscomma(char sign)
{
	return (sign == '.');
}

int	ft_isvalid(char **av, int i, int j)
{
	int	comma;

	while (av[i])
	{
		j = 0;
		comma = 0;
		while (av[i][j])
		{
			if ((!ft_isdigit(av[i][j]) && !ft_issign(av[i][j])
			&& !ft_iscomma(av[i][j]))
				|| (ft_isdigit(av[i][j]) && ft_issign(av[i][j + 1]))
				|| (ft_issign(av[i][j]) && !ft_isdigit(av[i][j + 1])))
				return (0);
			if (ft_iscomma(av[i][j]))
				comma++;
			j++;
		}
		if (comma >= 2)
			return (0);
		i++;
	}
	return (1);
}

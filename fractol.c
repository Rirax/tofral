/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:35:56 by rlechapt          #+#    #+#             */
/*   Updated: 2015/01/13 19:37:28 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mdlb_init(void)
{
	t_env	e;

	e.flag = 1;
	e.zoom = 0.5;
	e.moveX = 0;
	e.moveY = 0;
	e.WIDTH = 600;
	e.HEIGHT = 600;
	e.iteration_max = 100;
	mlx_settings(&e);
}

void	jlia_init(void)
{
	t_env	e;

	e.flag = 2;
	e.zoom = 0.5;
	e.moveX = 0;
	e.moveY = 0;
	e.WIDTH = 600;
	e.HEIGHT = 600;
	e.iteration_max = 150;
	mlx_settings(&e);
}

void	bdha_init(void)
{
	t_env	e;

	e.flag = 3;
	e.zoom = 0.5;
	e.moveX = 0;
	e.moveY = 0;
	e.WIDTH = 600;
	e.HEIGHT = 600;
	e.iteration_max = 100;
	mlx_settings(&e);
}

int		print_param(void)
{
	ft_putendl("chose a  fractal parameter:");
	ft_putendl(" _mandelbrot");
	ft_putendl(" _julia");
	ft_putendl(" _mandelbar");
	return (0);
}

int		main(int argc, char **argv)
{
	int		flag;
	char	*mdlb;
	char	*jlia;
	char	*mdlr;

	mdlb = "mandelbrot";
	jlia = "julia";
	mdlr = "mandelbar";
	if (argc != 2)
		return (print_param());
	else
	{
		if (ft_strcmp(argv[1], mdlb) == 0)
			mdlb_init();
		else if (ft_strcmp(argv[1], jlia) == 0)
			jlia_init();
		else if (ft_strcmp(argv[1], mdlr) == 0)
			bdha_init();
		else
			return (print_param());
	}
	return (0);
}

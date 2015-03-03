/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:35:56 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 11:02:13 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mdlb_init(void)
{
	t_env	e;

	e.flag = 1;
	e.zoom = 0.5;
	e.movex = 0;
	e.movey = 0;
	e.width = 600;
	e.height = 600;
	e.iter_max = 100;
	mlx_settings(&e);
}

void	jlia_init(void)
{
	t_env	e;

	e.flag = 2;
	e.zoom = 0.5;
	e.movex = 0;
	e.movey = 0;
	e.width = 600;
	e.height = 600;
	e.iter_max = 150;
	mlx_settings(&e);
}

void	bdha_init(void)
{
	t_env	e;

	e.flag = 3;
	e.zoom = 0.5;
	e.movex = 0;
	e.movey = 0;
	e.width = 600;
	e.height = 600;
	e.iter_max = 100;
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

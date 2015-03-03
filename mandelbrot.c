/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 22:54:05 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 09:36:28 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_mandelbrot(t_env *e, int x, int y)
{
	double	tmp;
	int		i;

	e->cr = e->x1 + (x - e->width / 2) /
		(e->zoom * e->width / 2) + e->movex;
	e->ci = e->y1 + (y - e->height / 2) /
		(e->zoom * e->height / 2) + e->movey;
	e->zr = (double)e->x;
	e->zi = (double)e->y;
	i = 0;
	while (e->zr * e->zr + e->zi * e->zi < 4 && i < e->iter_max)
	{
		tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * e->zi * tmp + e->ci;
		i++;
	}
	if (i == e->iter_max)
		get_color_julia(e, x, y, i);
	else
		get_color_julia(e, x, y, i);
}

void	mandelbrot(t_env *e)
{
	int		x;
	int		y;

	ft_clear_image(e);
	x = 0;
	while (x < e->width)
	{
		y = 0;
		while (y < e->height)
		{
			calcul_mandelbrot(e, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

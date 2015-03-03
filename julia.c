/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 22:52:17 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 09:37:38 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color_julia(t_env *e, int x, int y, int i)
{
	if (i < e->iter_max * 10 / 100)
		e->color = e->green3;
	else if (i >= e->iter_max * 10 / 100 && i < e->iter_max * 20 / 100)
		e->color = e->green3;
	else if (i >= e->iter_max * 20 / 100 && i < e->iter_max * 30 / 100)
		e->color = e->greeen;
	else if (i >= e->iter_max * 30 / 100 && i < e->iter_max * 40 / 100)
		e->color = e->yellow;
	else if (i >= e->iter_max * 40 / 100 && i < e->iter_max * 50 / 100)
		e->color = e->orange;
	else if (i >= e->iter_max * 50 / 100 && i < e->iter_max * 60 / 100)
		e->color = e->red;
	else if (i >= e->iter_max * 60 / 100 && i < e->iter_max * 70 / 100)
		e->color = e->fushia;
	else if (i >= e->iter_max * 70 / 100 && i < e->iter_max * 80 / 100)
		e->color = e->violet;
	else if (i >= e->iter_max * 80 / 100 && i < e->iter_max * 90 / 100)
		e->color = e->blue;
	else if (i >= e->iter_max * 90 / 100 && i < e->iter_max)
		e->color = e->turcoise;
	else if (i == e->iter_max)
		e->color = e->black;
	draw_image(e, x, y);
}

void	calcul_julia(t_env *e, int x, int y)
{
	double	tmp;
	int		i;

	e->cr = (double)e->x;
	e->ci = (double)e->y;
	e->zr = e->x1 + (x - e->width / 2) /
		(e->zoom * e->width / 2) + e->movex;
	e->zi = e->y1 + (y - e->height / 2) /
		(e->zoom * e->height / 2) + e->movey;
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

void	julia(t_env *e)
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
			calcul_julia(e, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

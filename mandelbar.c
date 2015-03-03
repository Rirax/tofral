/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:19:57 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 09:38:26 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_mandelbar(t_env *e, int x, int y)
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
		e->zi = -(2 * e->zi * tmp + e->ci);
		i++;
	}
	get_color_julia(e, x, y, i);
}

void	mandelbar(t_env *e)
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
			calcul_mandelbar(e, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:19:57 by rlechapt          #+#    #+#             */
/*   Updated: 2015/01/13 19:47:25 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbar(t_env *e)
{
	int		x;
	int		y;
	double	tmp;
	int		i;

	ft_clear_image(e);
	x = 0;
	while (x < e->WIDTH)
	{
		y = 0;
		while (y < e->HEIGHT)
		{
			e->cr = e->x1 + (x - e->WIDTH / 2) /
				(e->zoom * e->WIDTH / 2) + e->moveX;
			e->ci = e->y1 + (y - e->HEIGHT / 2) /
				(e->zoom * e->HEIGHT / 2) + e->moveY;
			e->zr = (double)e->x;
			e->zi = (double)e->y;
			i = 0;
			while (e->zr * e->zr + e->zi * e->zi < 4 && i < e->iteration_max)
			{
				tmp = e->zr;
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
				e->zi = -(2 * e->zi * tmp + e->ci);
				i++;
			}
			get_color_julia(e, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

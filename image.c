/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:44:38 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 10:32:10 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_image(t_env *e, int x, int y)
{
	e->p = y * e->sizeline + (e->bpp / 8) * x;
	ft_memcpy(&e->data[e->p], &e->color, (e->bpp / 8));
}

void	set_color(t_env *e)
{
	e->white = mlx_get_color_value(e->mlx, 0xFFFFFF);
	e->black = mlx_get_color_value(e->mlx, 0x000000);
	e->green3 = mlx_get_color_value(e->mlx, 0x007653);
	e->green2 = mlx_get_color_value(e->mlx, 0x34A281);
	e->green1 = mlx_get_color_value(e->mlx, 0x82CDB6);
	e->red = mlx_get_color_value(e->mlx, 0xCD1049);
	e->fushia = mlx_get_color_value(e->mlx, 0xCD10CD);
	e->violet = mlx_get_color_value(e->mlx, 0x5510CD);
	e->blue = mlx_get_color_value(e->mlx, 0x104FCD);
	e->turcoise = mlx_get_color_value(e->mlx, 0x10ADCD);
	e->green = mlx_get_color_value(e->mlx, 0x10CDA1);
	e->greeen = mlx_get_color_value(e->mlx, 0x63D930);
	e->yellow = mlx_get_color_value(e->mlx, 0xEAE317);
	e->orange = mlx_get_color_value(e->mlx, 0xDE9C3A);
}

void	ft_clear_image(t_env *e)
{
	int	x;
	int	y;

	x = -1;
	while (++x < e->width)
	{
		y = -1;
		while (++y < e->height)
			ft_memcpy(e->data + (y * e->sizeline) + (x * (e->bpp / 8)),
					&e->black, e->bpp / 8);
	}
}

int		ft_coord(int x, int y, t_env *e)
{
	e->x = (((double)(x - (e->width / 2)) / (e->width / 2)) / e->zoom) + e->x1;
	e->y = (((double)(y - (e->height / 2)) / (e->height / 2)) /
			e->zoom) + e->y1;
	return (0);
}

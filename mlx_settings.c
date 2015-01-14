/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 22:48:04 by rlechapt          #+#    #+#             */
/*   Updated: 2015/01/13 19:59:49 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_hook(t_env *e)
{
	if (e->x != e->xsav || e->y != e->ysav || e->zoom != e->zsav ||
		  e->moveX != e->xmsav || e->moveY != e->ymsav)
	{
		if (e->flag == 1)
			mandelbrot(e);
		else if (e->flag == 2)
			julia(e);
		else if (e->flag == 3)
			mandelbar(e);
		e->xsav = e->x;
		e->ysav = e->y;
		e->zsav = e->zoom;
		e->xmsav = e->moveX;
		e->ymsav = e->moveY;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double	relative_x;
	double	relative_y;
	printf("zoom: %f\n", e->zoom);
	if (button == 5)
	{
		e->zoom *= 1.01;
		relative_x = ((double)x - e->WIDTH / 2) / (e->WIDTH / 2);
		relative_y = ((double)y - e->HEIGHT / 2) / (e->HEIGHT / 2);
		e->x1 += 0.01 * relative_x / e->zoom;
		e->y1 += 0.01 * relative_y / e->zoom;
	}
	if (button == 4)
	{
		e->zoom /= 1.01;
		relative_x = ((double)x - e->WIDTH / 2) / (e->WIDTH / 2);
		relative_y = ((double)y - e->HEIGHT / 2) / (e->HEIGHT / 2);
		e->x1 -= 0.01 * relative_x / e->zoom;
		e->y1 -= 0.01 * relative_y / e->zoom;
	}
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 65361)
		e->moveX += 0.1 / e->zoom;
	if (keycode == 65363)
		e->moveX -= 0.1 / e->zoom;
	if (keycode == 65362)
		e->moveY += 0.1 / e->zoom;
	if (keycode == 65364)
		e->moveY -= 0.1 / e->zoom;
	if (keycode == 65307)
		exit (0);
	return (0);
}

int	expose_hook(t_env *e)
{
		ft_putnbr(e->flag);
		if (e->flag == 1)
			mandelbrot(e);
		else if (e->flag == 2)
			julia(e);
		else if (e->flag == 3)
			mandelbar(e);
	return(0);
}

void	mlx_settings(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->WIDTH, e->HEIGHT, "fractol");
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, (1l << 6), ft_coord, e);
	e->img = mlx_new_image(e->mlx, e->WIDTH, e->HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	set_color(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

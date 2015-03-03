/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:41:53 by rlechapt          #+#    #+#             */
/*   Updated: 2015/03/03 11:01:04 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <string.h>
# include "./libft/includes/libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	double		x;
	double		y;
	double		xsav;
	double		ysav;
	int			p;
	double		zoom;
	double		zsav;
	double		x1;
	double		y1;
	double		movex;
	double		movey;
	int			xmsav;
	int			ymsav;
	double		mxsv;
	double		mysv;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	int			flag;
	int			width;
	int			height;
	int			iter_max;
	int			color;
	int			black;
	int			white;
	int			green3;
	int			green2;
	int			green1;
	int			red;
	int			fushia;
	int			violet;
	int			blue;
	int			turcoise;
	int			green;
	int			greeen;
	int			yellow;
	int			orange;
}				t_env;

void			draw_image(t_env *e, int x, int y);
void			ft_clear_image(t_env *e);
void			mandelbrot(t_env *e);
void			julia(t_env *e);
void			mandelbar(t_env *e);
int				ft_coord(int x, int y, t_env *e);
void			mlx_settings(t_env *e);
void			set_color(t_env *e);
void			get_color_julia(t_env *e, int x, int y, int i);

#endif

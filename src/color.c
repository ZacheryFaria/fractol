/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:13:25 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 14:44:10 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>
#include <fractol.h>

t_coor	g_rainbow[7] = {
	{1.0, .8, RED},
	{.8, .6, ORANGE},
	{.6, .4, YELLOW},
	{.4, .15, GREEN},
	{.15, .05, BLUE},
	{.05, .0025, PURPLE},
	{.0025, 0, GRAY}
};

t_coor	g_pink[7] = {
	{1.0, .8, 0x82667F},
	{.8, .6, 0xB486AB},
	{.6, .4, 0xDD9AC2},
	{.4, .15, 0xDFAEB4},
	{.15, .05, 0xEACBD2},
	{.05, .0025, SILVER},
	{.0025, 0, WHITE}
};

t_coor	g_rand1[7] = {
	{1.0, .8, 0xB084CC},
	{.8, .6, 0xC7EFCF},
	{.6, .4, 0xEA8C55},
	{.4, .15, 0xFE5F55},
	{.15, .05, 0x34F6F2},
	{.05, .0025, 0x399E5A},
	{.0025, 0, 0x3454D1}
};

t_coor	g_rand2[7] = {
	{1.0, .8, 0x006E90},
	{.8, .6, 0xF18F01},
	{.6, .4, 0xE53D00},
	{.4, .15, 0xFFE900},
	{.15, .05, 0x34D1BF},
	{.05, .0025, 0xA23B72},
	{.0025, 0, 0x556F7A}
};

double	percent(double start, double end, double current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_col(t_coor start, t_coor end, double current)
{
	double	p;
	int		red;
	int		green;
	int		blue;

	p = percent(start.x, end.x, current);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}

int		get_color(int res, t_mlx *mlx)
{
	double	s;
	int		i;
	int		color;
	t_coor	*map;

	map = mlx->color;
	s = scale(res, (t_coor){0.0, 1.0, 0}, (t_coor){0, mlx->max_itr, 0});
	i = 0;
	while (i < 7)
	{
		if (s >= map[i].y && s < map[i].x)
		{
			if (i == 6)
				return (map[i].color);
			else
				color = get_col(map[i], map[i + 1], s);
		}
		i++;
	}
	return (color);
}

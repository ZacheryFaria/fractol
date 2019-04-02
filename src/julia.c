/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:14 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 17:43:18 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <colors.h>

#define MAX_ITR 255

int		calc_pixel(t_coor *coord, t_coor c, double zoom)
{
	int		itr;
	double	zx;
	double	zy;
	double	temp;

	itr = 0;
	zx = coord->x / zoom;
	zy = coord->y / zoom;
	while (itr < MAX_ITR && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy;
        zy = 2 * zx * zy + c.y;
        zx = temp + c.x;
		itr++;
	}
	return (itr);
}

void	*julia_run(void *ta)
{
	int		y;
	int		x;
	t_args	*args;
	t_mlx	*mlx;
	
	args = ta;
	mlx = args->mlx;
	y = args->start;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			t_coor p;
			p.x = scale(x + mlx->origin->x, X_SCALE, (t_coor){0, mlx->width - 1, 0});
			p.y = scale(y + mlx->origin->y, Y_SCALE, (t_coor){0, mlx->height - 1, 0});
			int res = calc_pixel(&p, (t_coor){-0.7, 0.27015, 0}, mlx->zoom);
			if (res == MAX_ITR)
				image_set_pixel(mlx, &(t_coor){x, y, 0}, BLACK);
			else
			{
				double s = scale(res, (t_coor){0.0, 1.0, 0}, (t_coor){0, MAX_ITR, 0});
				if (s > 0.8)
				{
					int color = get_color((t_coor){1.0, 0, RED}, (t_coor){.8, 0, ORANGE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.6)
				{
					int color = get_color((t_coor){0.8, 0, ORANGE}, (t_coor){.6, 0, YELLOW}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.4)
				{
					int color = get_color((t_coor){.6, 0, YELLOW}, (t_coor){.4, 0, GREEN}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.2)
				{
					int color = get_color((t_coor){.4, 0, GREEN}, (t_coor){.2, 0, BLUE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.1)
				{
					int color = get_color((t_coor){.2, 0, BLUE}, (t_coor){.1, 0, PURPLE}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else if (s > 0.25)
				{
					int color = get_color((t_coor){.1, 0, PURPLE}, (t_coor){.25, 0, GRAY}, (t_coor){s, 0, 0}, (t_coor){1, 0, 0});
					image_set_pixel(mlx, &(t_coor){x, y, 0}, color);
				}
				else
				{
					image_set_pixel(mlx, &(t_coor){x, y, 0}, GRAY);
				}
				
			}
			x++;
		}
		y += mlx->threads;
	}
	return (0);
}

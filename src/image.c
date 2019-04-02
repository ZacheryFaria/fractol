/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:58:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 13:25:21 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fractol.h>
#include <stdio.h>

t_image	*image_new(t_mlx *mlx)
{
	t_image *ret;

	if (!(ret = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(ret->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height)))
	{
		free(ret);
		return (NULL);
	}
	ret->ptr = (int *)mlx_get_data_addr(ret->img, &ret->bpp,
		&ret->wid, &ret->end);
	return (ret);
}

void	image_set_pixel(t_mlx *mlx, t_coor *vec, int color)
{
	if (vec->y + 1 >= mlx->height)
		return ;
	if (!(vec->x < 0 || vec->x >= mlx->width)
		&& !(vec->y < 0 || vec->y >= mlx->height))
		mlx->img->ptr[(int)(vec->x + (vec->y * mlx->img->wid / 4))] = color;
}

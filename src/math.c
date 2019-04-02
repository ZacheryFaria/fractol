/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:38:31 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 16:15:37 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double scale(double point, t_coor scale, t_coor scale2)
{
	double m;

	m = point - scale2.x;
	m /= scale2.y - scale2.x;
	m *= scale.y - scale.x;
	m += scale.x;
	return (m);
}

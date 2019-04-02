/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 09:41:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/02 13:01:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <math.h>

typedef struct	s_image
{
	void		*img;
	int			*ptr;
	int			bpp;
	int			wid;
	int			end;
}				t_image;

typedef struct	s_coor
{
	double		x;
	double		y;
	int			color;
}				t_coor;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	int			width;
	int			height;
	t_coor		*origin;
	double		zoom;
	t_coor		mouse_p;
	t_coor		mouse_c;
	int			update;
	int			threads;
	int			max_itr;
	t_coor		*c;
	void		*(*f)();
}				t_mlx;

typedef	struct	s_args
{
	int			start;
	t_mlx		*mlx;
}				t_args;

typedef struct	s_dispatch
{
	char		*key;
	void		(*func)(t_mlx *mlx);
}				t_dispatch;

# define X_SCALE (t_coor){-1.0, 1.0, 0}
# define Y_SCALE (t_coor){-1.0, 1.0, 0}

void			*julia_run(void *args);
void			*mandelbrot_run(void *args);

int				event_key(int keycode, void *param);
int				event_close(void);
int				event_mouse(int x, int y, void *ptr);
int				fdf_loop(void *ptr);
int				event_mouse_pressed(int keycode, int x, int y, void *ptr);
int				event_mouse_released(int keycode, int x, int y, void *ptr);
int				julia_mouse_move(int x, int y, void *ptr);

int				get_color(t_coor start, t_coor end, t_coor current, t_coor d);

double			scale(double point, t_coor scale, t_coor scale2);

t_image			*image_new(t_mlx *mlx);
void			image_set_pixel(t_mlx *mlx, t_coor *vec, int color);
void			image_plot_line(t_mlx *mlx, t_coor v1, t_coor v2, t_coor orig);
int				get_light(int start, int end, double percent);

t_coor			*new_coor(double x, double y, int color);

t_list			*read_file(char *str, int *len);
char			*basename(char *s);

void			plot_map(t_mlx *mlx);
void			redraw(t_mlx *mlx);
void			startup_threads(t_mlx *mlx);

void			*die(char *str);

#endif

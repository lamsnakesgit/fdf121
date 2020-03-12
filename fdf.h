/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:10:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/12 21:09:24 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

//#include "minilibx_macos/mlx.h"
# include <mlx.h>

# include <fcntl.h>
# include <math.h>
# define BS 16000
# define WHITE 0xffffff
# define REVWHITE 0xff00ff

# define RED 0xe80c0c
# define CYAN 0xffff
# define PINK 0xff00ff
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define GRAY 0xfffff0

# define CLR 0x00FF00
# define WIN_W_X 500
# define ISO_ANG 0.523599
# define PRL 35
# define ISO 34
# define ESC 53

# define ANGLE 0
# define Y_DOWN 126
# define Y_UP 125
# define X_DOWN 123
# define X_UP 124
# define UP_Z 91
# define DOWN_Z 84
# define UP_Y 89
# define DOWN_Y 92
# define UP_X 86
# define DOWN_X 88

/*
** change the type of projection
** handle keys/mouse one by one
** color
** gradient
** hidden surfaces
*/

typedef	struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		delta_x;
	int		delta_y;
	int		x2;
	int		y2;
	int		z2;
}				t_coord;

typedef struct	s_fdf
{
	int		w;
	int		h;
	int		**z_matrix;
	int		fd;
	char	*fname;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	z_sh;
	int		sl;
	void	*mlx_ptr;
	void	*win_ptr;
	int		projection;
	int		rot_y;
	int		rot_x;
	int		rot_z;
	void	*img_ptr;
	int		*img;
	int		bpp;
	int		endian;
	float	angle_y;
	float	angle_x;
	float	angle_z;
	int		dy;
	int		dx;
	int		er;
	int		er2;
	int		sy;
	int		sx;
	int		z;
	int		z2;
}				t_fdf;

void			draw_line(t_fdf *fdf);
int				ft_count_w(char *s, char c);
int				deal_mouse(int m, t_fdf *fdf);
int				mouse_press(int button, int x, int y, void *param);
int				ft_err();
void			isometric(int *x, int *y, int z);
void			rot_y(float *x, float *y, float *z, float angle);
void			rot_z(float *x, float *y, float *z, float angle);
int				deal_mouse(int m, t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);
void			draw_line(t_fdf *fdf);
void			findpb(t_coord crd, int x1, int y1, t_fdf *fdf);
float			mod(float a);
char			**lines(char *buf, t_fdf *f);
char			**processmap(int fd, t_fdf *f);
int				ft_blank(void *img, int szline);
void			x_rotate(t_fdf *fdf, int *y, int *z);
void			y_rotate(t_fdf *fdf, int *x, int *z);
void			z_rotate(t_fdf *fdf, int *x, int *y);
int				free_map(char **line);
void			ft_modify(t_fdf *fdf, t_coord *crd);
int				get_high(t_fdf *fdf);
int				get_width(t_fdf *fdf);
void			fill_matrix(int *z_line, char *line);
int				calc_high(t_fdf *fdf, char **map);
int				free_z(t_fdf *fdf, int i);
int				calc_size(t_fdf *fdf);

#endif

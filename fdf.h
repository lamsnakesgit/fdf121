/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:10:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/04 18:58:45 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

//#include "minilibx_macos/mlx.h"
# include <mlx.h>

# include <fcntl.h>
# include <math.h>
# define WHITE 0xffffff
# define RED 0xe80c0c
# define ISO_ANG 0.523599
# define PRL 1
# define ISO 3
# define ESC 53
# define Y_DOWN 126
# define Y_UP 125
# define X_DOWN 123
# define X_UP 124

# define UP_Z 4
# define UP_Y 44
# define UP_X 444
# define DOWN_Z 4444
# define DOWN_Y 44444
# define DOWN_X 4444444


/*
** change the type of projection
** handle keys/mouse one by one
** color
** gradient
** hidden surfaces
*/

typedef	struct	s_coord
{
	float	x;
	float	y;
	int		z;
}				t_coord;

typedef struct	s_fdf
{
	int		w;
	int		h;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z_sh;

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
}				t_fdf;

void	draw_line(t_fdf *fdf);
int		ft_count_w(char *s, char c);
int		deal_mouse(int m, t_fdf *fdf);
int		mouse_press(int button, int x, int y, void *param);
int		ft_err();









#endif
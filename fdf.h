/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:10:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/29 21:40:49 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

# include <fcntl.h>
# include <math.h>
# define WHITE 0xffffff
# define RED 0xe80c0c

typedef struct	s_fdf
{
	int		w;
	int		h;
	int		**z_matrix;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int ft_count_w(char *s, char c);

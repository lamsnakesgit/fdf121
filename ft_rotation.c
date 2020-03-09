
#include "fdf.h"
//==ROTATION x
//	y = y * cos(angle) + z * sin(ANGLE);
//	z = -y * sin(angle) + z cos(ANGLE);
//ROTZ
void 		rot_z(float *x, float *y, float *z, float angle)
{
	float prev_y;
	float prev_z;

	prev_y = *y;
	prev_z = *z;
//	x = x * cos(angle) - y * sin(angle);
//	y = x * sin(angle) + y * cos(angle);
	*y = cos(angle);
	*z = sin(angle);
}

void 		rot_y(float *x, float *y, float *z, float angle)
{
	float prev_y;
	float prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = cos(angle);
	*z = sin(angle);
//ROTY
//	x = x * cos(angle) + z * sin(angle);
//	z = -x * cos(angle) + z * cos(angle);
}

//void		isometric (float *x, float *y, int z, t_fdf *fdf)
void		isometric (int *x, int *y, int z, t_fdf *fdf)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);//(0.8);
	*y = (prev_x + prev_y) * sin(0.523599) -z * fdf->z_sh;//(0.8) - z;
}

void	x_rotate(t_fdf *fdf, int *y, int *z)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->angle_x) + *z * sin(fdf->angle_x);
	*z = -prev_y * sin(fdf->angle_x) + *z * cos(fdf->angle_x);
}

void	y_rotate(t_fdf *fdf, int *x, int *z)
{
	int prev_x;

	prev_x = *x;
	*x = prev_x * cos(fdf->angle_y) + *z * sin(fdf->angle_y);
	*z = -prev_x * sin(fdf->angle_y) + *z * cos(fdf->angle_y);
}

void	z_rotate(t_fdf *fdf, int *x, int *y)
{
	int prv_x;
	int prv_y;

	prv_x = *x;
	prv_y = *y;
	*x = prv_x * cos(fdf->angle_z) - prv_y * sin(fdf->angle_z);
	*y = prv_x * sin(fdf->angle_z) + prv_y * cos(fdf->angle_z);
}

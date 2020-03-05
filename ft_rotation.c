
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

void		isometric(float *x, float *y, int z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);//(0.8);
	*y = (prev_x + prev_y) * sin(0.523599) -z ;//(0.8) - z;
}

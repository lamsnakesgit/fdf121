#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int main()
{
	void *p;
	p = mlx_init();
	//printf("%p");
	mlx_new_image(p, 10000,10000);
	//mlx_hook(p, 10000000, 100000);
	mlx_destroy_image();
	return (0);
}

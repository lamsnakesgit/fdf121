#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int main()
{
	void *p;
//	p = mlx_init();
	int color;
	int i = 0;
	char ar[4]={0};
	color = 0xffffff;
	while (i < 5)
	{
		ar[i] = color;
		printf("ari=%d\n", ar[i]);
		ar[++i] = color >> 8;
		printf("ari=%d\n", ar[i]);
		ar[++i] = color >>16;
		printf("ari=%d\n", ar[i]);
		ar[++i] = 99;//9;//9;
		printf("ari=%d\n", ar[i]);
		break;
	}
	printf("clr=%d", color);
	//printf("%p");
//	mlx_new_image(p, 10000,10000);
	//mlx_hook(p, 10000000, 100000);
//	mlx_destroy_image();
	return (0);
}

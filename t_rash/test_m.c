#include "fdf.h"

int main()
{
	int *m;
	int i = 0;
	m = (int *)malloc(sizeof(int) * 4);
	while (i < 2600959 )
	{
		printf("i=%d\n", i);
		printf("mi=%d\n", m[i]);
		++i;
	}
	return (0);
}

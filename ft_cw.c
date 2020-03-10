#include "fdf.h"

int			ft_count_w(char  *s, char c)
{
	int i;
	int	word;

	i = 0;
	printf("=%s=\n", s);
	while (s[i] && s[i] == c)
    {
        printf("BP1.1.1.1.111cw\n");
        ++i;
    }
	word = 0;
    printf("BP1.1.1.1.111cw\n");
    while (s[i])
	{
		if (s[i] != c)
			++word;
        printf("BP1.1.1.1.111cw\n");
        while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (word);
}

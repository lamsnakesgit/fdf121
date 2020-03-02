#include "fdf.h"

int			ft_count_w(char  *s, char c)
{
	int i;
	int	word;

	i = 0;
	while (s[i] && s[i] == c)
		++i;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
			++word;
		while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (word);
}

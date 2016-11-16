#include "../../includes/ft_sh1.h"

char*		ft_chardup(char c)
{
	char*	str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}


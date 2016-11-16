#include "../../includes/ft_sh1.h"

void		ft_free_strarray(char ***array)
{
	char **ptr;

	ptr = *array;
	while (*ptr)
	{
		free(*ptr++);
	}
	free(*array);
}


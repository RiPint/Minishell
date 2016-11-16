#include "../../includes/ft_sh1.h"

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (1);
}

void		ft_put_histo(t_env *e)
{
	t_str *ptr;

	ptr = e->histo;
	tputs("\n\x1B[33mThe historic is :\n\x1B[00m", 1, ft_putc);
	while (ptr)
	{
		if (ptr->str)
		{
			tputs(ptr->str, 1, ft_putc);
			tputs("\n", 1, ft_putc);
		}
		ptr = ptr->next;
	}
	tputs("\n", 1, ft_putc);
}

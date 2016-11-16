/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:56:11 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:56:28 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

int			ft_clear_imput(t_env *e)
{
	int		len;

	len = e->index;
	if (((ft_strlen(e->name) + ft_strlen(e->str)) % tgetnum("co")) == 0)
	{
		len--;
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	}
	while (len--)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	tputs(tgetstr("cd", (char **)(&e->p->buf)), 1, ft_putc);
	return (0);
}

void		ft_clean_histo(t_env *e)
{
	t_str	*ptr;

	ptr = e->histo;
	while (ptr)
	{
		if (ptr->tmp)
		{
			free(ptr->tmp);
			ptr->tmp = NULL;
		}
		ptr = ptr->next;
	}
}

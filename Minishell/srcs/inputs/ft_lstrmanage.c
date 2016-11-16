/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:58:40 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:58:54 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

void		ft_lststr_add(t_str **lst, t_str *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst)->past = new;
	*lst = new;
}

t_str		*ft_lststr_new(char *str)
{
	t_str	*tmp;

	tmp = (t_str *)ft_memalloc(sizeof(t_str));
	tmp->str = ft_strdup(str);
	tmp->past = NULL;
	tmp->next = NULL;
	return (tmp);
}

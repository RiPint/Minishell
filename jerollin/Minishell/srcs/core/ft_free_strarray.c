/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:28:18 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:28:32 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

void		ft_free_strarray(char ***array)
{
	char	**ptr;

	ptr = *array;
	while (*ptr)
	{
		free(*ptr++);
	}
	free(*array);
}

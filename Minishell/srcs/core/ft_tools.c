/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:30:14 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:50:39 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

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

void		ft_error_2char(char *str, char *str2)
{
	ft_putstr(str);
	ft_putendl(str2);
}

char		*ft_linkpath(char *s1, char *s2, char c)
{
	char	*str;
	char	*ptr;
	char	*p1;
	char	*p2;

	p1 = s1;
	p2 = s2;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!(str = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	ptr = str;
	while (*p1)
		*ptr++ = *p1++;
	*ptr++ = c;
	while (*p2)
		*ptr++ = *p2++;
	*ptr = '\0';
	return (str);
}

char		*ft_redup(char **str)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	free(*str);
	*str = tmp;
	return (*str);
}

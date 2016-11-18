/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envtools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:26:36 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:26:38 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

char		**ft_get_env_addr(t_env *shell, char *name)
{
	char	**ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr))
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char		*ft_get_env_value(t_env *shell, char *name)
{
	char	**ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr))
			return (ft_strdup(ft_strchr(*ptr, '=') + 1));
		ptr++;
	}
	return (NULL);
}

int			ft_namematch(char *name, char *var)
{
	int		i;
	int		len;

	len = ft_strlen(name);
	i = 1;
	while (*name && ft_toupper(*name) == ft_toupper(*var))
	{
		name++;
		var++;
		i++;
	}
	if (*var == '=' && len == i - 1)
		return (1);
	return (0);
}

int			ft_value_exist(t_env *shell, char *name)
{
	char	**ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr) && *(*ptr + ft_strlen(name) + 2))
			return (1);
		ptr++;
	}
	return (0);
}

void		ft_exit(t_env *shell)
{
	int		i;

	i = 0;
	while (shell->env[i])
		free(shell->env[i++]);
	if ((shell)->env)
		free(shell->env);
	i = 0;
	while (shell->av[i])
		free(shell->av[i++]);
	if (shell->av)
		free(shell->av);
	shell->pid = 0;
	exit(shell->pid);
}

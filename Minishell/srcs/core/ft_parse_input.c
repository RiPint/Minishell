/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:29:35 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:30:08 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static int		ft_commandmatch(char *name, char *test)
{
	while (*name && *name == *test)
	{
		name++;
		test++;
	}
	if (!*name && !*test)
		return (1);
	return (0);
}

static void		ft_print_environ(t_env *shell)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (shell->env)
	{
		while (ft_commandmatch("env", shell->av[j]) && shell->av[j + 1])
			j++;
		if (ft_commandmatch("env", shell->av[j]))
		{
			while (shell->env[i])
			{
				ft_putstr(shell->env[i]);
				ft_putstr("\n");
				++i;
			}
		}
		else
		{
			shell->binpath = ft_strdup(shell->av[j]);
			ft_exec_bin(shell);
		}
	}
}

static int		ft_count_arg(char **av)
{
	int		i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

void			ft_parse_input(t_env *shell)
{
	if (*shell->str)
	{
		shell->av = ft_parse_args(shell, shell->str);
		if ((shell->ac = ft_count_arg(shell->av)))
		{
			if (ft_commandmatch("env", shell->av[0]))
				ft_print_environ(shell);
			else if (ft_commandmatch("setenv", shell->av[0]))
				ft_setenv(shell);
			else if (ft_commandmatch("unsetenv", shell->av[0]))
				ft_unsetenv(shell);
			else if (ft_commandmatch("exit", shell->av[0]))
				ft_exit(shell);
			else if (ft_commandmatch("cd", shell->av[0]))
				ft_cd(shell);
			else
				ft_exec_bin(shell);
		}
		if (shell->av)
			ft_free_strarray(&shell->av);
	}
}

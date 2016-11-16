/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:03:43 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 18:06:55 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
#include <stdio.h>

BYPASS				*sing_oldterm(BYPASS *term)
{
	static BYPASS	*old;

	if (term != NULL)
		old = term;
	return (old);
}

void				ft_sig_to_reload(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (sig_num == SIGINT)
	{
		if (wait(NULL) == -1)
		{
			if (shell->cpid)
			{
				write(0, "\b\b \n", 3);
				shell->cpid = 0;
			}
			else
			{
				write(1, "\n", 1);
				ft_putstr(shell->name);
				if (shell->str == NULL)
					free(shell->str);
				shell->str = ft_strdup("");
				shell->index = 0;
				shell->max = 0;
			}
		}
	}
}

void				ft_sigterm(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	ft_putstr("\nBigBro: \x1B[31mTrying to kill me is useless !!!\n\x1B[00m");
	free(shell->str);
	shell->str = ft_strdup("");
	shell->index = 0;
	shell->max = 0;
	return ;
	(void)sig_num;
}

void				ft_sig_to_exit(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (!(shell->cpid))
	{
		tcsetattr(0, 0, sing_oldterm(NULL));
		signal(sig_num, SIG_DFL);
		kill(getpid(), sig_num);
	}
}

void				ft_init_signals(void)
{
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGTRAP, ft_sig_to_exit);
	signal(SIGABRT, ft_sig_to_exit);
	signal(SIGEMT, ft_sig_to_exit);
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	signal(SIGSEGV, ft_sig_to_exit);
	signal(SIGSYS, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGTERM, SIG_IGN);
	signal(SIGURG, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGIO, SIG_IGN);
	ft_init_signals_suite();
}

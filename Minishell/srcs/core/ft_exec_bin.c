#include "../../includes/ft_sh1.h"
#include <sys/stat.h>

t_env*		ft_call_env(t_env **shell)
{
	static t_env*save;

	if (shell && *shell)
	{
		save = *shell;
		return (NULL);
	}
	else
		return (save);
}

static void	ft_wrong_exit2(int sig_num)
{
	if (sig_num == SIGBUS)
		write(1, ": \x1B[31mbus error\x1B[00m ", 25);
	else if (sig_num == SIGSEGV)
		write(1, ": \x1B[31msegmentation fault\x1B[00m ", 34);
	else if (sig_num == SIGALRM)
		write(1, ": \x1B[31mti\x1B[00m", 17);
	else if (sig_num == SIGXCPU)
		write(1, ": \x1B[31mcpu limit exceeded\x1B[00m ", 34);
	else if (sig_num == SIGXFSZ)
		write(1, ": \x1B[31msize limit exceeded\x1B[00m ", 35);
	else if (sig_num == SIGVTALRM)
		write(1, ": \x1B[31mvirtual time alarm\x1B[00m ", 34);
	else if (sig_num == SIGPROF)
		write(1, ": \x1B[31mprofile signal shell\x1B[00m", 35);
	else if (sig_num == SIGUSR1)
		write(1, ": \x1B[31muser-defined signal 1 shell\x1B[00m", 42);
	else if (sig_num == SIGUSR2)
		write(1, ": \x1B[31muser-defined signal 2 shell\x1B[00m", 42);
}

void		ft_wrong_exit(char *father, int sig_num, char *son)
{
	if (sig_num == SIGPIPE)
		return ;
	ft_putstr(father);
	if (sig_num == SIGHUP)
		write(1, ": \x1B[31mhangup\x1B[00m ", 22);
	else if (sig_num == SIGILL)
		write(1, ": \x1B[31millegal hardware instruction\x1B[00m ", 44);
	else if (sig_num == SIGTRAP)
		write(1, ": \x1B[31mtrace trap shell\x1B[00m", 31);
	else if (sig_num == SIGABRT)
		write(1, ": \x1B[31mabort\x1B[00m ", 21);
	else if (sig_num == SIGFPE)
		write(1, ": \x1B[31mfloating point exception\x1B[00m ", 40);
	else if (sig_num == SIGKILL)
		write(1, ": \x1B[31mkilled\x1B[00m ", 22);
	else
		ft_wrong_exit2(sig_num);
	ft_putendl(son);
}

static int	ft_set_binpath(t_env *shell)
{
	inti;

	i = 0;
	if (shell->path != NULL)
	{
		if (access(shell->av[0], X_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->paths[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->paths[i++],\
							shell->av[0], '/')))
			{
				if (access(shell->binpath, X_OK) == 0)
					return (0);
				free(shell->binpath);
			}
		}
		ft_error_2char("shell: no such file or directory: ", shell->av[0]);
	}
	else
		ft_error_2char("Undefined environment PATH :", shell->av[0]);
	return (-1);
}

void		ft_exec_bin(t_env *shell)
{
	intstat_loc;

	if (ft_set_binpath(shell) == 0)
	{
		shell->cpid = fork();
		if (shell->cpid != -1)
		{
			if (shell->cpid == 0)
				execve(shell->binpath, shell->av, shell->env);
			else
				waitpid(shell->cpid, &stat_loc, 0);
		}
		if (WIFSIGNALED(stat_loc))
			ft_wrong_exit(shell->name_shell,
					WTERMSIG(stat_loc), shell->binpath);
		free(shell->p);
		free(shell->binpath);
		shell->p = ft_get_params();
		shell->cpid = 0;
	}
}

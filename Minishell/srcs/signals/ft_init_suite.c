/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:04:07 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 18:07:14 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

void		ft_init_signals_suite(void)
{
	signal(SIGXCPU, ft_sig_to_exit);
	signal(SIGXFSZ, ft_sig_to_exit);
	signal(SIGVTALRM, ft_sig_to_exit);
	signal(SIGPROF, ft_sig_to_exit);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGINFO, SIG_IGN);
	signal(SIGUSR1, ft_sig_to_exit);
	signal(SIGUSR2, ft_sig_to_exit);
}

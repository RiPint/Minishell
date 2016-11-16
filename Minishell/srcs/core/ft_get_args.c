/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:28:39 by jerollin          #+#    #+#             */
/*   Updated: 2016/11/16 17:29:29 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static char			*ft_get_word(char **str, char *quote)
{
	char	*ptr;
	char	*word;

	if (!(word = (char *)ft_memalloc(sizeof(char) * ft_strlen(*str))))
		return (NULL);
	ptr = word;
	while (*(*str))
	{
		if (!*quote && *(*str) == '\\')
			*ptr++ = *++(*str);
		else
		{
			if (!*quote && (*(*str) == '\'' || *(*str) == '"'))
				*quote = *(*str);
			else if (*quote && *(*str) == *quote)
				*quote = '\0';
			else if (!*quote && (*(*str) == ' ' || *(*str) == '\t'))
				break ;
			else
				*ptr++ = *(*str);
		}
		(*str)++;
	}
	*ptr = '\0';
	return (ft_redup(&word));
}

static size_t		ft_parse_loop(t_env *shell, char **str, char quote)
{
	return (0);
	shell++;
	str++;
	quote++;
}

static size_t		ft_parse_len(t_env *shell, char **str)
{
	char	*tmp;
	char	*ptr;
	char	quote;
	size_t	v;

	quote = '\0';
	v = 0;
	ptr = *str;
	if (*(*str + ft_strlen(*str)) == '\\')
		return (ft_parse_loop(shell, str, '\\'));
	while (*ptr)
	{
		tmp = ft_get_word(&ptr, &quote);
		free(tmp);
		while (*ptr && (*ptr == ' ' || *ptr == '\t'))
			ptr++;
		v++;
	}
	if (quote)
		return (ft_parse_loop(shell, str, quote));
	return (v);
}

char				**ft_parse_args(t_env *shell, char *input)
{
	char	**argv;
	char	**ptr;
	int		len;
	char	quote;

	quote = '\0';
	len = ft_parse_len(shell, &input);
	if (!input)
		return (NULL);
	if (!(argv = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ptr = argv;
	while (len-- && *input)
	{
		*ptr = ft_get_word(&input, &quote);
		if (**ptr)
			ptr++;
		else
			free(*ptr);
		while (*input == ' ' || *input == '\t')
			input++;
	}
	*ptr = NULL;
	return (argv);
}

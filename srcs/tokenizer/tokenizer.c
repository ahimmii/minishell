/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:45:31 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:49:29 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static bool	is_redirection(char *s)
{
	return ((*s == '<' && *(s + 1) == '<') \
			|| (*s == '>' && *(s + 1) == '>') \
			|| (*s == '<') || (*s == '>')
	);
}

static t_list	*quote_error(void)
{
	printf("syntax error: missing to close quotes\n");
	return (NULL);
}

static char	*special(char *s, t_list **tokens, t_gc **garbage)
{
	t_list	*last_token;
	int		n;
	int		i;

	last_token = ft_lstlast(*tokens);
	n = 1;
	if ((*s == '>' && *(s + 1) == '>') || (*s == '<' && *(s + 1) == '<'))
		n = 2;
	if (last_token->content)
		ft_lstadd_back(tokens, \
			collect(ft_lstnew(collect(ft_substr(s, 0, n), garbage)), garbage));
	else
	{
		i = -1;
		while (++i < n)
			last_token->content = \
				collect(append_char(last_token->content, *(s + i)), garbage);
	}
	if (*(s + n) && !is_space(*(s + n + 1)) && *(s + n + 1))
		ft_lstadd_back(tokens, collect(ft_lstnew(NULL), garbage));
	s += n;
	return (s);
}

t_list	*tokenize(char *s, t_gc **garbage)
{
	t_list	*tokens;
	t_list	*token;

	tokens = NULL;
	if (!is_space(*s))
		ft_lstadd_back(&tokens, collect(ft_lstnew(NULL), garbage));
	while (*s)
	{
		if ((!tokens || is_space(*s)) && (*(s + 1) && !is_space(*(s + 1))))
			ft_lstadd_back(&tokens, collect(ft_lstnew(NULL), garbage));
		while (*s == '|' || is_redirection(s))
			s = special(s, &tokens, garbage);
		token = ft_lstlast(tokens);
		if (*s == '\'' || *s == '"')
		{
			s = handle_quotes(s, &tokens, garbage);
			if (*s != '\'' && *s != '"')
				return (quote_error());
		}
		else if (tokens && !is_space(*s))
			token->content = collect(append_char(token->content, *s), garbage);
		if (*s)
			s++;
	}
	return (tokens);
}

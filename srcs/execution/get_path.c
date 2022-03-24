/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:48:58 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:51:52 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_cwd(char *word)
{
	if (*word == '.' && *(word + 1) == '/')
	{
		if (access(word, F_OK) == 0 && access(word, X_OK) != 0)
			return (true);
		return (false);
	}
	return (false);
}

char	*get_path(char *word, t_var *env, t_gc **garbage)
{
	char	**cmd;
	char	*path;
	int		i;

	if (!word || !*word || !env || check_cwd(word))
		return (NULL);
	if (access(word, X_OK) == 0)
		return (word);
	path = ft_getenv("PATH", env);
	cmd = ft_split(path, ':');
	if (!cmd)
		return (NULL);
	i = -1;
	while (cmd[++i])
	{
		collect(cmd[i], garbage);
		cmd[i] = collect(append_char(cmd[i], '/'), garbage);
		cmd[i] = collect(ft_strjoin(cmd[i], word), garbage);
		if (access(cmd[i], X_OK) == 0)
			return (free(cmd), cmd[i]);
	}
	return (free(cmd), NULL);
}

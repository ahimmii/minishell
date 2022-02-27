/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:48:58 by aklaikel          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:07 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *word, t_var *env, t_gc **garbage)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	if (!word || !env)
		return (NULL);
	if (access(word, F_OK) == 0)
		return (word);
	path = ft_getenv("PATH", env);
	cmd = ft_split(path, ':');
	if (!cmd)
		return (NULL);
	while (cmd[i])
	{
		collect(cmd[i], garbage);
		cmd[i] = collect(append_char(cmd[i], '/'), garbage);
		cmd[i] = collect(ft_strjoin(cmd[i], word), garbage);
		if (access(cmd[i], F_OK) == 0)
			return (free(cmd), cmd[i]);
		i++;
	}
	return (free(cmd), NULL);
}
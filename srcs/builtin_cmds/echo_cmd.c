/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:10:02 by ahimmi            #+#    #+#             */
/*   Updated: 2022/03/24 21:01:07 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_newline(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] != 'n')
			return (1);
	return (0);
}

static void	print_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		ft_putstr_fd(words[i++], 1);
		if (words[i])
			ft_putstr_fd(" ", 1);
	}
}

void	echo_cmd(char **cmd_list)
{
	int		i;
	bool	is_set;

	if (!cmd_list || !*cmd_list || ft_strncmp(cmd_list[0], "echo", 255))
		return ;
	i = 1;
	is_set = true;
	while (cmd_list[i] && cmd_list[i][0] == '-')
	{
		if (!valid_newline(cmd_list[i]))
			is_set = false;
		else
			break ;
		i++;
	}
	print_words(&cmd_list[i]);
	if (is_set)
		ft_putstr_fd("\n", 1);
}

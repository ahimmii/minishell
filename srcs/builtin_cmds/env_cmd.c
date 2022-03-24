/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:10:02 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:53:05 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(char **cmd_list, t_var *env)
{
	t_var	*var;

	var = env;
	if (!cmd_list || !*cmd_list || ft_strncmp(*cmd_list, "env", 255))
		return ;
	if (cmd_list[1])
	{
		g_tools.exit_status = 1;
		if (cmd_list[1][0] == '-' \
			&& cmd_list[1][1] != '\0' && cmd_list[1][1] != '-')
			err_printf("%s: illegal option -- %c\n", cmd_list[0], \
				cmd_list[1][1]);
		err_printf("usage: env [with no options] [with no arguments]\n");
		return ;
	}
	while (var)
	{
		if (var->value)
			printf("%s=%s\n", var->name, var->value);
		var = var->next;
	}
}

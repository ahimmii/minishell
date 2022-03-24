/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:44:19 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:53:36 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_var	*get_last(t_var *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back(t_var **lst, t_var *new)
{
	t_var	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{	
		last_node = get_last(*lst);
		last_node->next = new;
	}
}

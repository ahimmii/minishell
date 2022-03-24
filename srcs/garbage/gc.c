/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:48:13 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:51:49 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include <stdio.h>

void	clear(t_gc **garbage)
{
	t_gc	*tmp;

	while (*garbage)
	{
		tmp = (*garbage)->next;
		free((*garbage)->rubbish);
		free(*garbage);
		*garbage = tmp;
	}
}

static void	allocaiton_error(t_gc **garbage)
{
	perror("Error");
	clear(garbage);
	exit(0);
}

void	*collect(void *rubbish, t_gc **garbage)
{
	t_gc	*bin;

	if (!garbage)
		return (NULL);
	if (!rubbish)
		allocaiton_error(garbage);
	bin = malloc(sizeof(t_gc));
	if (!bin)
		allocaiton_error(garbage);
	bin->rubbish = rubbish;
	bin->next = (*garbage);
	(*garbage) = bin;
	return (rubbish);
}

void	*gc_malloc(size_t size, t_gc **garbage)
{
	return (collect(malloc(size), garbage));
}

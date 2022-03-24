/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freadline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:20:08 by ahimmi            #+#    #+#             */
/*   Updated: 2022/03/24 20:50:05 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*freadline(char *prompt, char *color, t_gc **garbage)
{
	char	*prom;
	char	*arrow;

	if (g_tools.exit_status != 0)
		arrow = RED;
	else
		arrow = GREEN;
	prom = collect(ft_strjoin(arrow, "➜  "), garbage);
	prom = collect(ft_strjoin(prom, color), garbage);
	prom = collect(ft_strjoin(prom, "\033[1m"), garbage);
	prom = collect(ft_strjoin(prom, prompt), garbage);
	prom = collect(ft_strjoin(prom, " "), garbage);
	prom = collect(ft_strjoin(prom, RESET), garbage);
	return (readline(prom));
}

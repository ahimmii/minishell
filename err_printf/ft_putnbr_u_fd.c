/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 01:51:36 by akarafi           #+#    #+#             */
/*   Updated: 2022/03/24 20:55:59 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr_u_fd(unsigned int n, int *len, int fd)
{
	unsigned int	i;

	i = n;
	if (i <= 9)
	{
		ft_putchar_fd(i + 48, fd);
		(*len)++;
	}
	else
	{
		ft_putnbr_fd(i / 10, len, fd);
		ft_putnbr_fd(i % 10, len, fd);
	}
}

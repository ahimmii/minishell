/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:32 by ayoub          #+#    #+#             */
/*   Updated: 2022/03/24 20:55:42 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr_fd(int n, int *len, int fd)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		(*len)++;
		i = -1 * i;
	}
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

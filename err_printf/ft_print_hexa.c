/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:28:42 by ayoub             #+#    #+#             */
/*   Updated: 2022/03/24 20:55:11 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned long num, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (num <= 15)
	{
		ft_putchar_fd(base[num], 1);
		(*len)++;
	}
	else
	{
		ft_print_hexa(num / 16, len);
		ft_print_hexa(num % 16, len);
	}
}

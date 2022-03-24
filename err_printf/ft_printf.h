/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:15:42 by ayoub             #+#    #+#             */
/*   Updated: 2022/03/24 20:55:02 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

int		err_printf(const char *f, ...);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int *len, int fd);
void	ft_putnbr_u_fd(unsigned int n, int *len, int fd);
int		ft_printstr(char *s);
void	print_it(char c, va_list ptr, int *len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_hexa(unsigned long num, int *len);
void	ft_print_uhexa(unsigned long num, int *len);

#endif
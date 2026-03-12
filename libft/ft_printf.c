/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:05:53 by anmuller          #+#    #+#             */
/*   Updated: 2026/01/21 10:08:10 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr_printf(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_putnbr_int(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else
		return (write(1, "%%", 1));
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	size_t		char_num;
	va_list		args;

	i = 0;
	char_num = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			char_num += format(str[i + 1], args);
			i = i + 2;
		}
		else
			char_num += ft_putchar_printf(str[i++]);
	}
	va_end(args);
	return (char_num);
}
/* #include <stdlib.h>
#include <stdio.h>
int main()
{
	int num1 = printf(NULL, NULL);
	printf("\nnum1 = %d\n", num1);
	int num2 = ft_printf(NULL, NULL);
	ft_printf("\nnum2 = %d\n", num2);
	return 0;
} */
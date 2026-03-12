/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:43:45 by anmuller          #+#    #+#             */
/*   Updated: 2026/01/21 11:17:02 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_printf(char c);

int	ft_putnbr_int(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_printf('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr_int(nbr / 10);
	count += ft_putchar_printf(nbr % 10 + '0');
	return (count);
}
/* #include <stdio.h>
int	main(void)
{
	int	test;

	test = ft_putnbr_int(-2147483648);
	write(1,"\n",1);
	printf("%d\n", test);

	return (1);
} */

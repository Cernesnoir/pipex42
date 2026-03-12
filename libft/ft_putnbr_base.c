/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:12:32 by anmuller          #+#    #+#             */
/*   Updated: 2026/01/21 10:27:15 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				count_char;
	unsigned int	len;

	count_char = 0;
	len = ft_strlen(base);
	if (nbr >= len)
		count_char += ft_putnbr_base(nbr / len, base);
	count_char += ft_putchar_printf(base[nbr % len]);
	return (count_char);
}
/* #include <stdio.h>
int	main(void)
{
	unsigned int test = ft_putnbr_base(42, "0123456789abcdef");

	write (1, "\n", 1);
	printf("%d\n", test);
	printf("%x\n",42);
	return (1);
} */

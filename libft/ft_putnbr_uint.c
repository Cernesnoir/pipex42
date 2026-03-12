/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:22:59 by anmuller          #+#    #+#             */
/*   Updated: 2026/01/21 11:11:23 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "libft.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_uint(uintptr_t nbr, char *base)
{
	uintptr_t	len;
	int			count_char;

	count_char = 0;
	len = ft_strlen2(base);
	if (nbr >= len)
		count_char += ft_putnbr_uint(nbr / len, base);
	count_char += ft_putchar_printf(base[nbr % len]);
	return (count_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:23:13 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/25 09:25:44 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "libft.h"

int	ft_putptr_printf(void *ptr)
{
	int			count_char;
	uintptr_t	u_ptr;

	count_char = 0;
	if (!ptr)
		count_char += ft_putstr_printf("(nil)");
	else
	{
		write(1, "0x", 2);
		count_char = 2;
		u_ptr = (uintptr_t)ptr;
		count_char += ft_putnbr_uint(u_ptr, "0123456789abcdef");
	}
	return (count_char);
}
/* #include <stdlib.h>
#include <stdio.h>
int main()
{
	void *ptr = 0;
	printf("%p %p\n", ptr, ptr);
	size_t test = ft_putptr_printf(ptr);
	write(1, "\n", 1);
	printf("%zu\n", test);
	return 0;
} */

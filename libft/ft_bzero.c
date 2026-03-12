/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:11:11 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/11 17:11:57 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)s;
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	size_t n = 5;
	char s[] = "HelloBob";
	ft_bzero(s, n);
	size_t i = 0;
	while (i < 8)
	{
		printf("%c\n", s[i]);
		i++;
	}
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:27:36 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 14:08:47 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*r1;
	const unsigned char	*r2;

	i = 0;
	r1 = (const unsigned char *) s1;
	r2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (r1[i] != r2[i])
			return (r1[i] - r2[i]);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	const char *s1 = "Hello World";
	const char *s2 = "Hello World";
	printf("%d\n",ft_memcmp(s1,s2,5));
	return 0;
}*/

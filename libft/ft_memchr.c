/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:50:16 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/15 08:42:45 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;

	result = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*result == (unsigned char) c)
			return ((void *) result);
		result++;
	}
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char *test = "Hello World"; 
	char *s = memchr(test, 'o', 5);
	printf("%s\n", s);
	char *s2 = ft_memchr(test, 'o' , 5);
	printf("%s\n",s2);
	return 0;
}*/

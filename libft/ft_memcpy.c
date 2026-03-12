/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:07:18 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 15:43:16 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*result;
	const unsigned char	*source;

	i = 0;
	result = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (!result && !source)
		return (NULL);
	while (i < n)
	{
		result[i] = source[i];
		i++;
	}
	return (result);
}
/*#include <stdio.h>
int	main()
{
	int n = 5;
	char dest[10] = "Good---Bob";
	char src[10] = "Hello";
	printf("%s\n",dest);
	ft_memcpy(dest, src, n);
	printf("%s\n", dest);
	return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:59:32 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/13 13:36:49 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((!dest && !src) || size == 0)
		return (ft_strlen(src));
	while (dest[j] != '\0')
	{
		j++;
	}
	if (j >= size)
	{
		return (size + ft_strlen(src));
	}
	while (src[i] != '\0' && ((j + i) < size - 1))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
/*#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char *src = "It's a beautiful day\0";

	char *dest = malloc(21);	
	size_t result = strlcat(dest, src, 21);
	printf("%zu\n", result);
	printf("%s\n", dest);
	printf("%s\n", "---------");
	
	char *dest2 = malloc(21);
	result = ft_strlcat(dest2, src, 21);
	
	printf("%zu\n", result);
	printf("%s\n", dest);
	
	return 0;
}*/

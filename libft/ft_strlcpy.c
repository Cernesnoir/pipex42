/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:46:58 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/13 13:37:41 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*#include <stdlib.h>
#include <bsd/string.h>
int	main(void){
	size_t size = 13;
	char *src = "Hello World!";
	char *dest = malloc(sizeof(char) * 23);
	
	printf("La taille de est de: %zu\n",ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	free(dest);
	printf("\n%s\n", "-------------");
	char *src2 = "Hello World!";
	char *dest2 = malloc(sizeof(char) * 23);
	printf("La taille est de : %zu\n", strlcpy(dest2, src2, size));
	printf("%s\n", dest2);
	free(dest2);
	return 0;
}*/

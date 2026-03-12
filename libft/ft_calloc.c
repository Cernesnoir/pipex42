/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:15:08 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 10:57:14 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
/*#include <stdio.h>
int main()
{
	int *test = ft_calloc(10, sizeof(int));
	for(int i = 0; i < 10; i++)
	{
		printf("%d", test[i]);
	}
	printf("\n%s\n", "---------");
	int *test2 = calloc(10, sizeof(int));
	for(int i = 0; i < 10; i++)
	{
		printf("%d", test2[i]);
	}
	return 0;
}*/

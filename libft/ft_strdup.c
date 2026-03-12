/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:06:53 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 15:29:29 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*dest;
	size_t		len;

	i = 0;
	len = ft_strlen(src);
	if (src == NULL)
		return (0);
	dest = (char *) malloc(len * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	const char *test = "Hello";
	printf("%s\n",ft_strdup(test));
	return 0;
}*/

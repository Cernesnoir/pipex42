/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:54:43 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/15 09:54:43 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (start >= ft_strlen(s))
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = (char) s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*#include <stdio.h>
int main()
{
	char *test = "Hello Bob";
	printf("%s\n",ft_substr(test, 6, 3));
	return 0;
}*/

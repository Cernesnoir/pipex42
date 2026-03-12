/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:26:38 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/13 13:38:40 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = (char *)str;
	result += ft_strlen(result);
	while (result >= str)
	{
		if (*result == (char) c)
			return (result);
		result--;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strrchr("Hello",'e'));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:03:51 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/11 14:54:41 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*result;

	result = (char *) str;
	while (*result != '\0')
	{
		if (*result == (char) c)
		{
			return (result);
		}
		result++;
	}
	if ((char)c == '\0')
		return (result);
	return (0);
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	const char str[] = "HelloHHH";
	const char str2[] = "HelloHHH";
	printf("%s\n",ft_strchr(str, 'l'));
	printf("%s\n", str2);
	return (0);
}*/

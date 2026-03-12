/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:12:37 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/13 09:40:03 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*result;
	const unsigned char	*source;

	result = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (n--)
		{
			*result++ = *source++;
		}
	}
	else
	{
		result += n;
		source += n;
		while (n--)
		{
			*--result = *--source;
		}
	}
	return (dest);
}
/* 
#include <stdio.h>
int	main()
{
	int n = 3;
	char arr[4] = "1234";
	
	printf("%s\n",arr);
	ft_memmove(arr, arr + 1, n);
	printf("%s\n", arr);
	return 0;
}
 */
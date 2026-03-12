/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:23:21 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/17 11:23:21 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	arr_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	if (n == 0)
		len++;
	else
	{
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	large_n;
	size_t	len;
	char	*result;

	large_n = (long) n;
	len = arr_len(large_n) + 1;
	result = malloc(len);
	if (result == NULL)
		return (NULL);
	result[--len] = '\0';
	len--;
	if (large_n < 0)
	{
		result[0] = '-';
		large_n *= -1;
	}
	else if (large_n == 0)
		result[0] = '0';
	while (large_n > 0)
	{
		result[len] = '0' + large_n % 10;
		large_n /= 10;
		len--;
	}
	return (result);
}
/*#include <stdio.h>
int main()
{
	printf("%s\n",ft_itoa(36));
	return 0;
}*/

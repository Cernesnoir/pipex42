/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:35:38 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 15:11:16 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
		{
			sign = -1;
		}
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = 10 * result + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("36"));
	return 0;
}*/

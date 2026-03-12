/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:43:08 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/14 13:13:18 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
	{
		return (1);
	}
	else
		return (0);
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalpha('s'));
	printf("%d\n", ft_isalpha('='));
	return 0;
}
 */

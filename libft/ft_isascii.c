/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:47:35 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/10 10:34:52 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
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
	printf("%d\n", ft_isascii('H'));
	printf("%d\n", ft_isascii('{'));
	return 0;
}*/

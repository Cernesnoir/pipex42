/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:38:33 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:28 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')
		|| (c <= '9' && c >= '0'))
	{
		return (1);
	}
	else
		return (0);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalnum('s'));
    printf("%d\n", ft_isalnum('5'));
    printf("%d\n", ft_isalnum('*'));
	return 0;
} */

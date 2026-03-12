/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:12:07 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/17 13:12:07 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stddef.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	remain;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		remain = n % 10 + '0';
		n /= 10;
		if (n > 0)
			ft_putnbr_fd(n, fd);
		write(fd, &remain, 1);
	}
}
/*int main()
{
	ft_putnbr_fd(42,1);
	return 0;
}*/

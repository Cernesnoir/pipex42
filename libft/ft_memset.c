/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:32:03 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/11 15:32:28 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *zone_vide, int valeur, size_t nombre)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)zone_vide;
	while (i < nombre)
	{
		result[i] = (unsigned char) valeur;
		i++;
	}
	return (zone_vide);
}
/*#include <stdio.h>
int main(void)
{
	size_t i = 0;
	size_t nombre = 5;
	int valeur = 'B';
	char zone_vide[11] = "Hello World";
	ft_memset(zone_vide, valeur, nombre);
	while (i < 11)
	{
		printf("%c\n", (unsigned char)zone_vide[i]);
		i++;
	}
	return 0;
}*/

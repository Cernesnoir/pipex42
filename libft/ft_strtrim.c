/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:37:46 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/15 11:37:46 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str);

int	is_c_in_str(char const *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		index_start;
	size_t		index_fin;
	char		*result;

	index_start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[index_start] && is_c_in_str(set, s1[index_start]))
		index_start++;
	index_fin = ft_strlen(s1);
	while (index_fin > index_start && is_c_in_str(set, s1[index_fin - 1]))
		index_fin--;
	result = malloc(index_fin - index_start + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (index_start < index_fin)
		result[i++] = (char) s1[index_start++];
	result[i] = '\0';
	return (result);
}
/*#include <stdio.h>
int main()
{
	printf("%s\n", ft_strtrim("aa---Hello----aaaa", "-a "));
	return 0;
}*/

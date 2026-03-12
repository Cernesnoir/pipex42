/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:42:20 by anmuller          #+#    #+#             */
/*   Updated: 2025/11/18 13:42:20 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	wordcount(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
			{
				count++;
				while (s[i] && s[i] != c)
					i++;
			}
		}
	}
	return (count);
}

char	*alloc_arr(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		j;
	char		**result;

	j = 0;
	result = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			result[j] = alloc_arr(s, c);
			if (!result || !result[j] || !result[j++])
				return (free_arr(result));
		}
		while (*s && *s != c)
			s++;
	}
	result[j] = NULL;
	return (result);
}
/*#include <stdio.h>
int	main()
{
	char *test = "Hello bob, how are you ?";
	char **t = ft_split(NULL, ' ');
	for(int i = 0; i < 6; i++)
	{
		printf("%s\n", t[i]);
	}
	printf("%s\n", t[0]);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 12:05:17 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/15 10:16:48 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*alloc_arr_pipex(char const *s)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = 1;
	while (s[len] && s[len] != '\'')
		len++;
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

size_t	len_pipex(char const *s, size_t i)
{
	if (s[i] && s[i] == '\'' && s[1] && s[1] == ' ')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		if (s[i] && s[i + 1])
			i++;
	}
	else
		i++;
	return (i);
}

size_t	wc_pipex(char const *s, char c)
{
	size_t	i;
	size_t	count;

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
				{
					if (s[i] == '\'')
						i = len_pipex(s, i);
					i++;
				}
			}
		}
	}
	return (count);
}

char	**split_pipex(char const *s, char c)
{
	size_t	j;
	char	**result;

	j = 0;
	result = malloc(sizeof(char *) * (wc_pipex(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (*s && *s == '\'' && s[1] && s[1] == ' ')
				result[j] = alloc_arr_pipex(s);
			else
				result[j] = alloc_arr(s, c);
			if (!result || !result[j] || !result[j++])
				return (free_arr(result));
		}
		while (*s && *s != c)
			s += len_pipex(s, 0);
	}
	result[j] = NULL;
	return (result);
}
/*Il faut prendre en compte les cas ou tr ' ' 'x' ou tr ' a' 'x'
Aussi grep "Hello World"

Pour tr il faut juste que le split prenne en compte les guillemet*/
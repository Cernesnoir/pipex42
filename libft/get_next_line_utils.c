/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:28:30 by anmuller          #+#    #+#             */
/*   Updated: 2025/12/11 08:40:11 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stash, char *s2)
{
	char	*result;

	if (!stash)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (NULL);
	result = malloc(ft_strlen_gnl(stash) + ft_strlen_gnl(s2) + 1);
	if (!result)
		return (clear_all(&stash, &stash));
	str_fill(&result, &stash, &s2);
	free(stash);
	return (result);
}

void	str_fill(char **result, char **str1, char **str2)
{
	int	i;
	int	j;

	i = 0;
	if (!result || !*str1 || !*str2)
		return ;
	while ((*str1)[i])
	{
		(*result)[i] = (*str1)[i];
		i++;
	}
	j = 0;
	while ((*str2)[j])
	{
		(*result)[i + j] = (*str2)[j];
		j++;
	}
	(*result)[i + j] = '\0';
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_gnl(char *src)
{
	size_t	i;
	char	*dest;
	size_t	len;

	i = 0;
	len = ft_strlen_gnl(src);
	if (!src)
		return (NULL);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

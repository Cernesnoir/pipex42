/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:26:29 by anmuller          #+#    #+#             */
/*   Updated: 2025/12/11 08:34:09 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*extract_line(char *stash)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = stash[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*extract_remain(char *stash)
{
	int		i;
	int		len;
	char	*remain;

	len = 0;
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
		return (clear_all(&stash, &stash));
	if (stash[len] == '\n')
		len++;
	remain = malloc(ft_strlen_gnl(stash) - len + 1);
	if (!remain)
		return (clear_all(&stash, &stash));
	i = 0;
	while (stash[len])
		remain[i++] = stash[len++];
	remain[i] = '\0';
	free(stash);
	return (remain);
}

char	*clear_all(char **buffer, char **stash)
{
	if (*buffer && buffer != stash)
		free(*buffer);
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

void	line_manager(char **stash, char *line)
{
	if (line)
		*stash = extract_remain(*stash);
	else
		clear_all(stash, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (clear_all(&buffer, &stash));
	bytes = read(fd, buffer, BUFFER_SIZE);
	while ((bytes) > 0)
	{
		buffer[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (ft_strchr_gnl(buffer, '\n') == 1)
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes < 0 && buffer && stash)
		return (clear_all(&buffer, &stash));
	line = extract_line(stash);
	line_manager(&stash, line);
	free(buffer);
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char *test;
	int file_des = open("giant_line_nl.txt", O_RDWR);
	while ((test = (get_next_line(file_des))) != NULL)
	{
		printf("New Line is: %s", test);
		free(test);
	}
	return (0);
} */

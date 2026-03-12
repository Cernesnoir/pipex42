/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:57:59 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/11 18:29:48 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **str1, char *str2, int fd1, int fd2)
{
	free_arr(str1);
	free(str2);
	close_fd(fd1, fd2);
	exit(EXIT_FAILURE);
}

int	close_all_fd(int fd_arr[2], int fd_files[2], const char *str)
{
	close_fd(fd_arr[0], fd_arr[1]);
	close_fd(fd_files[0], fd_files[1]);
	if (str)
		error(str);
	return (1);
}

void	close_fd_cmd(int fd_1, int fd_2, char *name_proc)
{
	close_fd(fd_1, fd_2);
	if (ft_strncmp(name_proc, "cmd2", 4) == 0)
		exit(127);
	else if (ft_strncmp(name_proc, "cmd1", 4) == 0)
		exit(0);
}

int	close_fd(int fd_1, int fd_2)
{
	if (fd_1 >= 0)
		close(fd_1);
	if (fd_2 >= 0)
		close(fd_2);
	return (1);
}

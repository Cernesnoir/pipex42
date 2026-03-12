/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:32:30 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/12 09:46:38 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	do_fork_cmd1(int fd_arr[], int fd_files[], char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		close_all_fd(fd_arr, fd_files, "fork");
	if (pid == 0)
	{
		if (fd_files[0] == -1)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		cmd1(fd_arr, fd_files, argv, envp);
	}
	return (pid);
}

int	do_fork_cmd2(int fd_arr[], int fd_files[], char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		close_all_fd(fd_arr, fd_files, "fork");
	if (pid == 0)
	{
		if (fd_files[1] == -1)
		{
			perror(argv[4]);
			exit(EXIT_FAILURE);
		}
		cmd2(fd_arr, fd_files, argv, envp);
	}
	return (pid);
}

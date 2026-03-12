/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:40:14 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/12 10:26:18 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd2(int fd_arr[], int fd_files[], char **argv, char **envp)
{
	char	*str;
	char	**args_split;

	close_fd(fd_arr[1], fd_files[0]);
	args_split = ft_split(argv[3], ' ');
	if (!args_split)
		close_fd_cmd(fd_arr[0], fd_files[1], "cmd2");
	str = search_cmd(args_split[0], envp);
	if (!str)
	{
		free_arr(args_split);
		close_fd_cmd(fd_arr[0], fd_files[1], "cmd2");
	}
	dup2(fd_arr[0], STDIN_FILENO);
	dup2(fd_files[1], STDOUT_FILENO);
	close_fd(fd_arr[0], fd_files[1]);
	if (execve(str, args_split, envp) == -1)
		error_execve(args_split, str, "cmd2");
}

void	cmd1(int fd_arr[], int fd_files[], char **argv, char **envp)
{
	char	*str;
	char	**args_split;

	close_fd(fd_arr[0], fd_files[1]);
	args_split = ft_split(argv[2], ' ');
	if (!args_split)
		close_fd_cmd(fd_arr[0], fd_files[0], "cmd1");
	str = search_cmd(args_split[0], envp);
	if (!str)
	{
		free_arr(args_split);
		close_fd_cmd(fd_arr[0], fd_files[0], "cmd1");
	}
	dup2(fd_arr[1], STDOUT_FILENO);
	dup2(fd_files[0], STDIN_FILENO);
	close_fd(fd_arr[1], fd_files[0]);
	if (execve(str, args_split, envp) == -1)
		error_execve(args_split, str, "cmd1");
}

int	main(int argc, char **argv, char **envp)
{
	int		status_cmd2;
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd_arr[2];
	int		fd_files[2];

	if (argc != 5)
		return (1);
	fd_files[0] = open(argv[1], O_RDONLY);
	fd_files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(fd_arr) == -1)
		return (error_pipe(fd_files[0], fd_files[1]));
	pid_1 = do_fork_cmd1(fd_arr, fd_files, argv, envp);
	pid_2 = do_fork_cmd2(fd_arr, fd_files, argv, envp);
	close_all_fd(fd_arr, fd_files, NULL);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, &status_cmd2, 0);
	if (WIFEXITED(status_cmd2))
		return (WEXITSTATUS(status_cmd2));
	return (1);
}

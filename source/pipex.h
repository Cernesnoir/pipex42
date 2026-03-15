/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:40:31 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/14 21:20:59 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

int		check_access(char **argv);
int		error_pipe(int fd1, int fd2);
int		close_fd(int fd_1, int fd_2);
int		close_all_fd(int fd_arr[2], int fd_files[2], const char *str);
void	free_all(char **str1, char *str2, int fd1, int fd2);
int		args_failure(char **argv);
int		error(const char *str);
void	cmd1(int fd_arr[], int fd_files[], char **argv, char **envp);
void	cmd2(int fd_arr[], int fd_files[], char **argv, char **envp);
void	error_perso(const char *str, int num, int fd1, int fd2);
int		do_fork_cmd1(int fd_arr[], int fd_files[], char **argv, char **envp);
int		do_fork_cmd2(int fd_arr[], int fd_files[], char **argv, char **envp);
void	error_execve(char **args_split, char *str, char *name_proc);
void	close_fd_cmd(int fd_1, int fd_2, char *name_proc);
char	*alloc_arr(char const *s, char c);
char	*search_cmd(char *cmd, char **envp);
char	**split_pipex(char const *s, char c);
char	**free_arr(char **arr);

#endif
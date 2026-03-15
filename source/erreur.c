/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:37:29 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/14 23:28:10 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_perso(const char *str, int num, int fd1, int fd2)
{
	ft_printf("%s\n", str);
	close_fd(fd1, fd2);
	exit(num);
}

int	error(const char *str)
{
	perror(str);
	if (ft_strncmp(str, "fork", 4) == 0 || ft_strncmp(str, "pipe", 4) == 0)
		exit(1);
	exit(EXIT_FAILURE);
	return (1);
}

int	error_pipe(int fd1, int fd2)
{
	perror("pipe");
	close_fd(fd1, fd2);
	return (1);
}

void	error_execve(char **args_split, char *str, char *name_proc)
{
	perror("execve");
	free_arr(args_split);
	free(str);
	if (ft_strncmp(name_proc, "cmd2", 4) == 0)
		exit(126);
	else if (ft_strncmp(name_proc, "cmd1", 4) == 0)
		exit(126);
}

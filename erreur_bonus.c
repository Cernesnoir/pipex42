/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:37:29 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/24 14:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_perso(t_pipex *p, const char *str, int num)
{
	if (p->pid)
		free(p->pid);
	if (p)
		free(p);
	ft_printf("%s\n", str);
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

int	error_pipe(t_pipex *p)
{
	perror("pipe");
	close_fd(p);
	return (1);
}

void	error_execve(char **args_split, t_pipex *p, char *str, char *name_proc)
{
	if (p->pid)
		free(p->pid);
	if (p)
		free(p);
	perror("execve");
	free_str(args_split);
	free(str);
	if (ft_strncmp(name_proc, "cmd2", 4) == 0)
		exit(126);
	else if (ft_strncmp(name_proc, "cmd1", 4) == 0)
		exit(126);
}

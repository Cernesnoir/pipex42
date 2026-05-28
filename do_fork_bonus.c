/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:32:30 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/28 23:34:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int **free_pipe(int **fd_arr, int i)
{
	while (i >= 0)
	{
		free(fd_arr[i]);
		i--;
	}
	free(fd_arr);
	return (NULL);
}

int **make_pipe(t_pipex *p, int **fd_pipe, int argc)
{
	int	i;

	i = 0;
	fd_pipe = malloc(sizeof(int *) * (argc - 4 - p->h_doc_offset));
	if (!fd_pipe)
		return (NULL);
	while (i < argc - 4 - p->h_doc_offset)
	{
		fd_pipe[i] = malloc(sizeof(int) * 2);
		if (!fd_pipe[i])
		{
			free_pipe(fd_pipe, i);
			return (NULL);
		}
		if (pipe(fd_pipe[i]) == -1)
		{
			free_pipe(fd_pipe, i);
			return (NULL);
		}
		i++;
	}
	return (fd_pipe);
}

void do_fork_cmd(t_pipex *p, char **argv, char **envp)
{
    int     i;
    pid_t   pid;

    i = 0;
    while (i < p->argc - 3 - p->h_doc_offset)
    {
        pid = fork();
        if (pid < 0)
            close_all_fd(p, "fork", p->argc);
        p->pid[i] = pid;
        if (pid == 0)
        {
            if (i == 0 && p->fd_files[0] == -1)
            {
                perror(argv[1]);
				close_all_fd(p, NULL, p->argc);
				free(p->pid);
                free(p);
                exit(EXIT_FAILURE);
            }
            cmd(p, i, argv, envp);
        }
        i++;
    }
}

/*void	do_fork_cmd(t_pipex *p, char **argv, char **envp)
{
	int i;
	
	i = make_fork(p, p->argc);
	if (i != -1)
	{
		if (p->pid[i] < 0)
			close_all_fd(p, "fork", p->argc);
		if (p->pid[i] == 0)
		{
			if (p->fd_files[0] == -1)
			{
				perror(argv[1]);
				close_all_fd(p, argv[1], p->argc);
				exit(EXIT_FAILURE);
			}
			cmd(p, i, argv, envp);
		}
	}
}

int make_fork(t_pipex *p, int argc)
{
	int i;

	i = 0;
	while (i < argc - 3)
	{
		p->pid[i] = fork();
		if (p->pid[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}*/

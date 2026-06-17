/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:05:19 by marvin            #+#    #+#             */
/*   Updated: 2026/05/21 14:05:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void init_struct(t_pipex *p, char **argv, int argc)
{
    if (!p)
        return ;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        p->h_doc_offset = 1;
        p->fd_files[0] = here_doc(argv[2]);
        p->fd_files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
    else
    {
        p->h_doc_offset = 0;
        p->fd_files[0] = open(argv[1], O_RDONLY);
	    p->fd_files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }
    p->pid = malloc(sizeof(pid_t) * (argc - 3 - p->h_doc_offset));
    p->argc = argc;
    p->fd_pipe = make_pipe(p, p->fd_pipe, argc);
}


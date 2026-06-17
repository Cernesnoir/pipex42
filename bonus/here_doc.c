/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:43:17 by marvin            #+#    #+#             */
/*   Updated: 2026/05/26 14:43:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void loop_h_doc(char *str, int pipe_fd[], int lim_len)
{
    char    *line;

    while (1)
    {
        ft_putstr_fd("> ", 1);
        line = get_next_line(0);
        if (!line)
            break ;
        if (ft_strncmp(line, str, lim_len) == 0
            && (line[lim_len] == '\n' || line[lim_len] == '\0'))
        {
            free(line);
            break ;
        }
        ft_putstr_fd(line, pipe_fd[1]);
        free(line);
    }
}

int here_doc(char *str)
{
    int     pipe_fd[2];
    int     lim_len;

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    lim_len = ft_strlen(str);
    loop_h_doc(str, pipe_fd, lim_len);
    get_next_line(-1);
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}

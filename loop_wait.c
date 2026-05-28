/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:55:34 by marvin            #+#    #+#             */
/*   Updated: 2026/05/28 23:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void loop_wait(t_pipex *pip, int *status_cmd, int argc)
{
    int i;

    i = 0;
    while (i < argc - 3 - pip->h_doc_offset)
	{
		waitpid(pip->pid[i], status_cmd, 0);
		i++;
	}
}
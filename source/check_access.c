/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:35:27 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/11 17:26:38 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char **argv)
{
	if (!access(argv[4], F_OK) && access(argv[4], W_OK) == -1)
	{
		perror(argv[4]);
		exit(1);
		return (0);
	}
	if (access(argv[1], R_OK) == -1)
		perror(argv[1]);
	return (1);
}

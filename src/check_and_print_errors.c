/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:44:18 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/24 00:02:30 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error_and_exit(char *argv, int index)
{
	if (index == 1)
	{
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(0);
	}
	else if (index == 2)
	{
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

void	ft_check_pipe(int fds[2])
{
	if (pipe(fds) == -1)
	{
		perror("Error: pipe failed");
		exit(1);
	}
}

void	ft_check_childpid(pid_t childpid)
{
	if (childpid == -1)
	{
		perror("Error: Failed to fork child process");
		exit(1);
	}
}

void	ft_check_fd(int fd, char *argv)
{
	if (fd == -1)
	{
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:57:30 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/24 00:01:26 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		exit(1);
	}
}

void	ft_child_in(char **envp, char **argv, int fds[2])
{
	char	**cmd1;
	int		fd_in;

	cmd1 = NULL;
	fd_in = open(argv[1], O_RDONLY);
	ft_check_rights(envp, argv[1], fd_in);
	close(fds[0]);
	dup2(fd_in, 0);
	close(fd_in);
	dup2(fds[1], 1);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1 || cmd1[0] == 0)
	{
		free(cmd1);
		ft_print_error_and_exit(argv[2], 1);
	}
	if (cmd1[0][0] == '/')
	{
		if (execve(argv[2], cmd1, envp) == -1)
			ft_print_error_and_exit(argv[2], 1);
	}
	else
		ft_add_mypath(envp, argv[2], cmd1, 0);
	close(fds[1]);
}

void	ft_child_out(char **envp, char **argv, int fds[2])
{
	char	**cmd2;
	int		fd_out;

	cmd2 = NULL;
	fd_out = 0;
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_check_fd(fd_out, argv[4]);
	close(fds[1]);
	dup2(fd_out, 1);
	close(fd_out);
	dup2(fds[0], 0);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2 || cmd2[0] == 0)
	{
		free(cmd2);
		ft_print_error_and_exit(argv[3], 2);
	}
	if (cmd2[0][0] == '/')
	{
		if (execve(argv[3], cmd2, envp) == -1)
			ft_print_error_and_exit(argv[3], 2);
	}
	else
		ft_add_mypath(envp, argv[3], cmd2, 0);
	close(fds[0]);
}

int	ft_check_wait_and_status(pid_t child, int *status)
{
	waitpid(child, status, 0);
	if (WIFEXITED(*status))
		if (WEXITSTATUS(*status))
			return (WEXITSTATUS(*status));
	return (0);
}

int	ft_check_status_close_parent(int fds[2], pid_t child, int *status)
{
	close(fds[0]);
	close(fds[1]);
	waitpid(child, status, 0);
	if (WIFEXITED(*status))
		if (WEXITSTATUS(*status))
			return (WEXITSTATUS(*status));
	return (0);
}

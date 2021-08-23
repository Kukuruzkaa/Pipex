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

void	ft_child_in(char **envp, char **argv, int fds[2])
{
	char	**cmd1;
	int		fd_in;

	cmd1 = NULL;
	fd_in = 0;
	fd_in = open(argv[1], O_RDONLY);
	ft_check_fd(fd_in, argv[1]);
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
	if (WIFEXITED(status))
		if (WEXITSTATUS(status))
			return (WEXITSTATUS(status));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	childpid1;
	pid_t	childpid2;
	int		wstatus;

	wstatus = 0;
	ft_check_argc(argc);
	ft_check_pipe(fds);
	childpid1 = fork();
	ft_check_childpid(childpid1);
	if (childpid1 == 0)
		ft_child_in(envp, argv, fds);
	else
	{
		childpid2 = fork();
		ft_check_childpid(childpid2);
		if (childpid2 == 0)
		{
			ft_child_out(envp, argv, fds);
			// waitpid(childpid1, &wstatus, 0);
			ft_check_wait_and_status(childpid1, &wstatus);
			// if (WIFEXITED(wstatus))
			// 	if (WEXITSTATUS(wstatus))
			// 		return (WEXITSTATUS(wstatus));
		}
		else
		{
			close(fds[0]);
			close(fds[1]);
			// waitpid(childpid2, &wstatus, 0);
			ft_check_wait_and_status(childpid2, &wstatus);
			// if (WIFEXITED(wstatus))
			// 	if (WEXITSTATUS(wstatus))
			// 		return (WEXITSTATUS(wstatus));
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:12:34 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/25 15:12:39 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			return (ft_check_wait_and_status(childpid1, &wstatus));
		}
		else
			return (ft_check_status_close_parent(fds, childpid2, &wstatus));
	}
	return (0);
}

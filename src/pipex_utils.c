/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:40:28 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/24 00:03:16 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freepath(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_getpath(char **envp)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			envp[i] += 5;
			path = ft_split(envp[i], ':');
			break ;
		}
		i++;
	}
	return (path);
}

void	ft_exec_error_print(char *argv)
{
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(1);
}

void	ft_add_mypath(char **envp, char *argv, char **cmds, int access_pathname)
{
	int		i;
	char	*cmd;
	char	*tmp;
	char	**mypath;

	i = -1;
	cmd = NULL;
	tmp = NULL;
	mypath = ft_getpath(envp);
	while (mypath[++i])
	{
		tmp = ft_strjoin(mypath[i], "/");
		cmd = ft_strjoin(tmp, cmds[0]);
		free (tmp);
		if (!access(cmd, X_OK))
			execve(cmd, cmds, envp);
		else
			access_pathname = 1;
		if (cmd)
			free(cmd);
	}
	if (access_pathname == 1)
		ft_exec_error_print(argv);
	ft_freepath(mypath);
	ft_freepath(cmds);
}

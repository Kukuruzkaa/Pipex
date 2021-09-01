/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:47:48 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/30 18:47:51 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_pwd(char **envp)
{
	int		i;
	char	*ppath;

	ppath = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PWD", 3) == 0)
		{
			envp[i] += 4;
			ppath = envp[i];
		}
	}
	return (ppath);
}

void	ft_check_rights(char **envp, char *argv, int fd)
{
	char	*pwd;
	char	*buff;
	char	*file_path;

	pwd = NULL;
	buff = NULL;
	file_path = ft_get_pwd(envp);
	buff = ft_strjoin(file_path, "/");
	pwd = ft_strjoin(buff, argv);
	free (buff);
	if (fd < 0 && access(pwd, F_OK) == 0)
	{
		ft_putstr_fd(argv, 1);
		ft_putstr_fd(": Permission denied\n", 2);
		free(pwd);
		exit(1);
	}
	else if (fd < 0)
	{		
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
}

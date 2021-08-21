/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:59:15 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/21 17:47:22 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

void	ft_freepath(char **tab);
char	**ft_getpath(char **envp);
void	ft_add_mypath(char **envp, char *argv, char **cmds,
			int access_pathname);
void	ft_check_argc(int argc);
void	ft_print_error_and_exit(char *argv, int index);
void	ft_check_pipe(int fds[2]);
void	ft_check_childpid(pid_t childpid);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:59:15 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/21 18:41:18 by ddiakova         ###   ########.fr       */
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
void	ft_check_fd(int fd, char *argv);
void	ft_child_in(char **envp, char **argv, int fds[2]);
void	ft_child_out(char **envp, char **argv, int fds[2]);
int		ft_check_wait_and_status(pid_t child, int *status);
int		ft_check_status_close_parent(int fds[2], pid_t child, int *status);
void	ft_free(char **mypath, char **cmds, char *argv);
void	ft_check_rights(char *argv);

#endif

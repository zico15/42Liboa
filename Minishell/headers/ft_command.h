/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/16 19:33:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_H
# define FT_COMMAND_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_command	t_command;
typedef struct s_list_cmd	t_list_cmd;

struct s_command
{
	pid_t				pid;
	char				path[100];
	char				*arg;
	int					fd[2];
	char				**commands;
	int					*(*input)(int fd[2]);
	void				(*init)(char *arg, char **envp);
	int					(*execute)(t_command *cmd, int input, int out);
	struct s_command	*next;
};

struct s_list_cmd
{
	t_command			*beging;
	t_command			*end;
	t_command			*this;

	t_command			*(*add)(t_command *cmd);
	t_command			*(*get)(int index);
	void				(*forEach)(void (*fun)(t_command **cmd));
	t_command			*(*teste)(t_command *cmd);
};

void					*new_list(void);
t_list_cmd				*list(t_list_cmd *t);
void					list_clear(t_command **c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 17:22:19 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

static int	*ft_input(t_command *previou, t_command *this)
{
	pipe(this->fd);
	if (this->path[0] && this->execute(this, previou->fd[0], this->fd[1]))
	{
		close(previou->fd[0]);
		close(previou->fd[1]);
		next_command(this);
	}
	else if (this->commands)
		printf("%s %s\n", __COMMAND_NOT_FOUND__, this->commands[0]);
	return (this->fd);
}

static int	execute(t_command *this, int input, int out)
{
	pid_t	pit;

	pit = fork();
	if (!pit)
	{
		if (dup2(input, 0) < 0 || dup2(out, 1) < 0 || \
		close(input) || close(out))
			exit(0);
		execve(this->path, this->commands, data()->envp);
		exit(0);
	}
	waitpid(pit, NULL, 0);
	close(input);
	close(out);
	return (1);
}

static void	init(t_command *this, char *arg, char **envp)
{
	char		*path;
	int			i;

	printf("arg: (%s)\n", arg);
		i = -1;
	while (envp[++i] && !string().contains(path, "PATH="))
		path = envp[i];
	this->commands = string().split(arg, ' ');
	get_path(this, arg, path);
	return ;
}

t_command	*new_command(char *arg)
{
	t_command	*c;

	c = malloc(sizeof(t_command));
	if (!c)
	{
		printf("err: %s\n", "malloc");
		return (0);
	}
	c->input = ft_input;
	c->init = init;
	c->execute = execute;
	c->arg = arg;
	c->next = NULL;
	c->path[0] = 0;
	c->commands = NULL;
	c->pid = data()->pid_base++;
	return (c);
}

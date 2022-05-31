/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 22:30:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	if (!(this->execute(this, previou->fd[0], this->fd[1])))
	{
		printf("asdasd");
		if (this->commands)
			print_msg_error(this, __COMMAND_NOT_FOUND__, 1);
		close(this->fd[1]);
	}
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

static int	execute(t_command *this, int input, int out)
{
	pid_t	pit;
	int		status;

	pit = fork();
	if (!pit)
	{
		if (!string().equals(this->path, this->commands[0]))
		{
			if (dup2(input, 0) < 0 || dup2(out, 1) < 0 || \
			close(input) || close(out))
				exit(0);
		}
		execve(this->path, this->commands, data()->envp);
		kill(terminal()->pid, SIGUSR1);
		write(2, "errro\n", 8);
		exit(0);
	}
	waitpid(pit, &status, 0);
	/*if (status)
		print_msg_error(this, NULL, );*/
	close(input);
	close(out);
	return (1);
}

static int	init(t_command *this, char *arg, char **envp)
{
	char		*path;
	int			i;

	i = -1;
	path = NULL;
	while (envp[++i] && !string().contains(path, "PATH="))
		path = envp[i];
	get_path(this, arg, path);
	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	return (1);
}

static int	*ft_destroy(t_command *this)
{
	static int	fd[2] = {-1, -1};

	if (this)
	{
		close(this->fd[0]);
		close(this->fd[1]);
		free_ob(this->arg);
		free_list(this->commands);
	}
	return (fd);
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
	c->destroy = ft_destroy;
	c->arg = arg;
	c->fd[0] = -1;
	c->fd[1] = -1;
	c->index = -1;
	c->next = NULL;
	c->path[0] = 0;
	c->commands = NULL;
	c->pid = data()->pid_base++;
	return (c);
}

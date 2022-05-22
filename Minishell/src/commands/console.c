/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 16:36:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buffer[BUFFER_SIZE];

	dup2(previou->fd[1], 1);
	close(previou->fd[1]);
	buffer[read(previou->fd[0], buffer, BUFFER_SIZE)] = 0;
	printf("%s", buffer);
	close(previou->fd[0]);
	next_command(this);
	return (this->fd);
}

t_command	*new_console(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

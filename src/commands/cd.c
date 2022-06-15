/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 16:39:05 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buff[BUFFER_SIZE];
	char	*str;
	char	*temp;

	temp = NULL;
	if (this->commands && *this->commands)
	{
		str = this->commands[1];
		if (str == NULL)
			str = "/";
		else if (string().equals_n(str, "~", 1))
		{
			temp = string().replace(str, terminal()->home, "~");
			str = temp;
		}
		if (chdir(str) != 0)
			print_msg_error(this, __COMMAND_NOT_FILE__, 2);
		str = string().copy(getcwd(buff, BUFFER_SIZE));
		(hashmap(terminal()->envp))->put(string().copy("PWD"), str);
		free_ob(temp);
	}
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_cd(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

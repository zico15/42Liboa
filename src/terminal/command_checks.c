/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/04 12:12:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	check_wildcards(t_command *this)
{
	char		*str;
	char		*paths;
	char		*exts;

	str = NULL;
	(void) this;
	if (string().size(str) > 1 && string().contains(str, "*"))
	{
		paths = terminal()->wildcards(str);
		if (paths)
		{
			exts = terminal()->get_exts(str);
			//NULL = string().replace(str, paths, exts);
			free_ob(str);
		}
	}
}

static char	*replace_dolar(char *str, void *env, char *dollar, char *key)
{
	char		*value;
	char		*new;
	t_element	*e;

	value = "";
	e = hashmap(env)->get_key(key);
	if (e)
		value = e->value;
	new = string().replace(str, value, dollar);
	free_ob(str);
	return (new);
}

char	*check_dolar(void *env, const char *line, int i, int size)
{
	char	buff[BUFFER_SIZE];
	char	*new;
	int		j;

	j = -1;
	new = string().trim(line);
	while (line && i <= size)
	{
		if (j >= 0 && (string().is_space(line[i]) || \
		line[i] == '$' || !line[i] || !string().isalnum(line[i])))
		{
			buff[j] = 0;
			j = -1;
			new = replace_dolar(new, env, buff, &buff[1]);
		}
		else if (j >= 0)
			buff[j++] = line[i];
		if (j == -1 && line[i] == '$' && is_quotes(line, i) != SINGLE_QUOTED \
		&& ++j > -1)
			buff[j++] = line[i];
		i++;
	}
	return (new);
}

void	__check_args(t_command *this)
{
	int	i;

	i = -1;
	if (!this)
		return ;
	/*check_wildcards(this);
	this->commands = string().split(this->arg, " ");*/
	i = -1;
	if (!this->path[0] && !access(this->commands[0], F_OK) && this->commands)
	{
		while (this->commands[0] && this->commands[0][++i])
			this->path[i] = this->commands[0][i];
		this->path[i] = 0;
	}
}

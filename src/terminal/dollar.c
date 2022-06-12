/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:21:51 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 13:49:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_pipex.h>

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

static int	is_valid(const char *str, int i, int j)
{
	if (str[i] == '_')
		return (1);
	if (string().is_space(str[i]) || str[i] == '$' || !str[i])
		return (0);
	if (!string().isalnum(str[i]))
		return (0);
	if (i > 0 && string().isnumber(_str(str[i - 1])))
		return (0);
	(void) j;
	return (1);
}

char	*check_dolar(void *env, const char *line, int i, int size)
{
	char	buff[BUFFER_SIZE];
	char	*new;
	int		j;

	if (!*line)
		return (string().copy(line));
	j = -1;
	new = string().trim(line);
	while (line && i <= size)
	{
		if (j >= 0 && !is_valid(line, i, j))
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

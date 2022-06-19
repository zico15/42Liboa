/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/19 11:06:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

// static void print_e(t_element *e, void *o)
// {
// 	(void) o;
// 	printf("T: (%s)\n", e->value);
// }

// static void print_l(t_element *e, void *o)
// {
// 	void *l;

// 	l = e->value;
// 	printf("================\n");
// 	array(l)->for_each(print_e, o);
// }
void	command_destroy_element(t_element	*e)
{
	t_command	*c;

	c = e->value;
	if (c)
		c->destroy(c);
	free_ob(e->key);
	free_ob(e);
}

static void	token_destroy_element(t_element	*e)
{
	void	*list;
	void	*this_list;

	list = e->value;
	this_list = this()->array;
	if (list)
		array(list)->destroy();
	array(this_list);
	free_ob(e->key);
	free_ob(e);
}

void	set_fun_destroy_token(t_element *e, void *o)
{
	(void) o;
	(void) e;
	e->destroy = token_destroy_element;
}

void	*token(char *line)
{
	void	*token;
	void	*list;

	if (!line)
		terminal()->destroy("\rexit");
	if (!*line)
		return (NULL);
	list = ft_divide_quotes(line);
	token = ft_divide_cmds(list, 0, 0);
	array(list)->destroy();
	free_ob(line);
	return (token);
}

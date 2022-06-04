/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/04 10:03:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_util.h>
#include <ft_string.h>

void	__base_for_each(void (*fun)(t_element *e, void *v), void *o)
{
	t_element	*temp;
	t_element	*select;
	int			index;

	if (!this()->array)
		return ;
	temp = (this()->array)->begin;
	index = 0;
	while (temp)
	{
		select = temp;
		select->index = index++;
		temp = temp->next;
		fun(select, o);
	}
}

t_element	*__base_set_element(int index, void *value)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			if (e->destroy)
				free_ob(e->value);
			e->value = value;
			return (e);
		}
		e = e->next;
		i++;
	}
	return (0);
}

void	__base_remove_element_index(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return ;
	e = (this()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			(this()->array)->remove(e);
			return ;
		}
		e = e->next;
		i++;
	}
}

char	**__to_str(void)
{
	t_element	*temp;
	char		**list;
	int			i;

	if (!this()->array)
		return (NULL);
	list = malloc(sizeof(char *) * ((this()->array)->size + 1));
	if (!list)
		return (NULL);
	i = 0;
	temp = (this()->array)->begin;
	while (temp)
	{
		list[i++] = string().copy(temp->value);
		temp = temp->next;
	}
	list[i] = NULL;
	return (list);
}

void	__destroy_element(t_element	*e)
{
	free_ob(e->key);
	free_ob(e->value);
	free_ob(e);
}

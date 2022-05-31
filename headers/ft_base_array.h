/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:09:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_ARRAY_H
# define FT_BASE_ARRAY_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	char				*key;
	void				*value;
	struct s_element	*next;
}	t_element;

typedef struct s_array
{
	t_element		*begin;
	t_element		*end;
	t_element		*next;
	int				size;
	t_element		*(*add)(void	*value);
	void			*(*get)(int	index);
	t_element		*(*set)(int index, void *value);
	t_element		*(*remove)(t_element	*e);
	void			(*remove_index)(int index);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
}	t_array;

typedef struct s_hasmap
{
	t_array			*list;
	int				(*size)(void);
	t_element		*(*put)(char *key, void	*value);
	t_element		*(*get_index)(int	index);
	t_element		*(*get_key)(char *key);
	void			(*remove_index)(int	index);
	void			(*remove_key)(char *key);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
}	t_hashmap;

void					*new_array(void);
t_array					*array(t_array *this);
void					*new_hashmap(void);
t_hashmap				*hashmap(t_hashmap *this);

#endif
//# -fsanitize=address -g
//valgrind --leak-check=full -s -v

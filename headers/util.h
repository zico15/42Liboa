/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 16:35:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <ft_terminal.h>
# include <ft_base_array.h>
# include <ft_command.h>
# include <ft_read_line.h>

typedef struct s_this
{
	t_list_cmd		*list;
	t_terminal		*terminal;
	t_array			*array;
	t_read			*read;
	t_array			*array_main;

}	t_this;

t_this					*this(void);

//						memory
int						free_ob(void *v);
int						free_list(char **str);
#endif

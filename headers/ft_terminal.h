/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 16:34:46 by amaria-m         ###   ########.fr       */
/*   Updated: 2022/05/26 22:26:45 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include <stdlib.h>
# include <stdio.h>
# include <ft_command.h>

typedef struct s_terminal	t_terminal;

struct s_terminal
{
	char				*title;
	int					fd[2];
	void				*commands;
	void				(*input)(void);
	t_terminal			*next;
};

t_terminal				*new_terminal(char *title);
char					**token(char *line);

//						commadas
t_command				*new_command(char *arg);
t_command				*new_console(char *arg);
t_command				*new_redirect_output(char *arg);
t_command				*new_redirect_input(char *arg);
t_command				*new_cd(char *arg);

#endif

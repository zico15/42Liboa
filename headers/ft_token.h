/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:03 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 11:49:52 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

#include <ft_pipex.h>

// TOKEN UTILS
char	**ft_exit();
int		ft_separator(char l);
int		ft_quotes(char	*letter);
char	**ft_lst_to_arr(void	*tokens);

// DOLLAR SIGN HANDELING
char    *ft_dollar(char *str);

// TOKEN FUCNTION (returns arr of commands)
char	**token(char *line);

#endif
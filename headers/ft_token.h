/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:03 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/06 19:54:15 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include <ft_pipex.h>

# define SEPARADOES "|<>"

// is_quotes,
// return 0 -> not quoted ()
// return 1 -> double quoted ("")
// return 2 -> single quoted ('')
// return 4 -> both quoted ("" '') (this is not possible i think)

// FOR is_quotes FUNCTION
enum e_quotes {
	NOT_QUOTED,
	DOUBLE_QUOTED,
	SINGLE_QUOTED,
	BOTH_QUOTED,
};

// TOKEN UTILS
void	*ft_send_exit(void);
int		ft_separator(const char *str);
void	*ft_divide_cmds(void *list);

// QUOTES HANDELING
int		is_quotes(const char *str, int index);
char	*ft_rmv_quotes(char *str);
void	*ft_divide_quotes(const char *str);

// TOKEN FUCNTION (returns arr of commands)
void	*token(char *line);

typedef struct s_token
{
	void	*list;
}		t_token;

#endif

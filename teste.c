/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 18:09:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_pipex.h>

// -fsanitize=address -g
//open $HOMEBREW_TEMP
//open $TMPDIR  
///tmp/edos-san/Homebrew/Temp
int	main(void)
{
	char	str[BUFFER_SIZE];
	scanf("%[^\n]", str);
	int i = -1;
	while (str[++i])
		printf("arr %i: %i c: %c\n", i, ft_inside_quotes(str, i), str[i]);
	return (0);
}
//system("leaks -- minishell");
// "'"'$TERM'"'"
// echo "''"'$TERM'"'"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:16 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 16:44:20 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*__join(const char *str1, const char *str2)
{
	char	*str;
	int		i;

	str = malloc(string().size((char *) str1) \
	+ string().size((char *) str2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (str1 && *str1)
		str[i++] = *str1++;
	while (str2 && *str2)
		str[i++] = *str2++;
	str[i] = 0;
	return (str);
}

/***
 * separador c or \n
 * ***/
char	**__split(char const *s, char c, int j, char **list)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (s && (*s == c || *s == '\n') && *s)
		s++;
	while (s && (*s != c && *s != '\n') && s[i])
		i++;
	if (i > 0)
		str = malloc((i + 1) * sizeof(char));
	if (i > 0)
		str[i] = 0;
	i = 0;
	while (s && str && s && (*s != c && *s != '\n') && *s)
		str[i++] = *s++;
	if (++j >= 0 && i)
		list = __split(s, c, j, list);
	else if (!list)
		list = malloc(j * sizeof(char *));
	if (list)
		list[--j] = str;
	return(list);
}

/*
copys n characters of string 
*/
char	*__copy_n(const char *str, int n)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	copy = malloc(n + 1);
	while (copy && str[++i] && i < n)
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

/*
return a copy of the string but without whitespace AROUND the string
*/
char	*__str_trim(const char *str)
{
	int		size;

	if (!str)
		return (NULL);
	while (str && *str && string().is_space(*str))
		str++;
	size = string().size(str) - 1;
	while (size > 0 && str[size] && string().is_space(*str))
		size--;
	return (string().copy_n(str, size + 1));
}

char	*__strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	i2;

	if (*needle == 0 || needle == NULL)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		i2 = i;
		while (needle[j] == haystack[i2] && i2 < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)&haystack[i]);
			j++;
			i2++;
		}
		i++;
	}
	return (NULL);
}

int	__equals(const char *str1, const char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] == str2[i]);
}

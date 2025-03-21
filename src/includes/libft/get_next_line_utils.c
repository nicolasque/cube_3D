/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:59:27 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/20 21:56:37 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(char *str)
{
	size_t	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_get(char *str, char chr)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i ++;
	}
	if (chr == '\0')
		return (&str[i]);
	return (NULL);
}

void	ft_memcpy_get(char *copy, char *origin, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		copy[i] = origin[i];
		i++;
	}
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*exit;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	s1_len = ft_strlen_get(s1);
	s2_len = ft_strlen_get(s2);
	exit = (char *)malloc(s1_len + s2_len + 1);
	if (exit == NULL)
		return (NULL);
	ft_memcpy_get(exit, s1, s1_len);
	ft_memcpy_get((exit + s1_len), s2, s2_len);
	exit[s1_len + s2_len] = '\0';
	free(s1);
	return (exit);
}

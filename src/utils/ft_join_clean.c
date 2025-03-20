/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:45:08 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/20 22:00:23 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

char	*ft_strjoin_clean_s1(char *s1, char *s2)
{
	char	*exit;
	int		i;
	char	*s1_head;

	s1_head = s1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (exit == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (ft_memdel(s1_head), exit);
}

char	*ft_strjoin_clean_s2(char *s1, char *s2)
{
	char	*exit;
	int		i;
	char	*s2_head;

	s2_head = s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (exit == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (ft_memdel(s2_head), exit);
}

char	*ft_strjoin_clean_s1_s2(char *s1, char *s2)
{
	char	*exit;
	int		i;
	char	*s1_head;
	char	*s2_head;

	s1_head = s1;
	s2_head = s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (exit == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (ft_memdel(s2_head), ft_memdel(s1_head), exit);
}

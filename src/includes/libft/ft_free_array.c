/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:19:52 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/24 15:21:53 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_memdel(split[i]);
		i++;
	}
	ft_memdel(split);
}
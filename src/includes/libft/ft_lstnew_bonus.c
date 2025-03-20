/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo < nquecedo@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:36:26 by nquecedo          #+#    #+#             */
/*   Updated: 2025/01/29 13:03:27 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstnew - Creates a new list token.
 * @content: The content to be placed in the new token.
 *
 * Return: A pointer to the new token, or NULL if the token could not be created.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(1 * sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	return (new_node);
}

/*
============================================================
test
============================================================
*/
// #include <assert.h>
// void	test_check_content()
// {
// 	int	*value;
// 	t_list *token;
// 	value = malloc(sizeof(int));
// 	*value = 5;
// 	token = (ft_lstnew(value));
//	assert(*(int *)(token->content) == 5);
// 	printf("Test de contenido pasado \n");
// 	free(value);
// 	free(token);
// }
// void	test_chec_newxr_null()
// {
// 	int	*value;
// 	t_list *token;
// 	value = malloc(sizeof(int));
// 	*value = 5;
// 	token = (ft_lstnew(value));
// 	assert(token->next == NULL);
// 	printf("Test de netxt null pasado \n");
// 	free(value);
// 	free(token);
// }
// int main()
// {
// 	test_check_content();
// 	test_chec_newxr_null();
// 	return (0);
// }

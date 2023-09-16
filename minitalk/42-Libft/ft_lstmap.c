/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knottey <Twitter:@knottey>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:56:12 by knottey           #+#    #+#             */
/*   Updated: 2023/05/17 14:24:15 by knottey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_elem;
	t_list	*tail;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail->next = new_elem;
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}

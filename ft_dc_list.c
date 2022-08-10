/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:13:27 by naharagu          #+#    #+#             */
/*   Updated: 2022/08/10 13:28:34 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dc_list	*ft_dc_lstnew(int content)
{
	t_dc_list	*tmp;

	tmp = malloc(sizeof(t_dc_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_dc_list	*ft_dc_lstlast(t_dc_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}


void	ft_dc_lstadd_back(t_dc_list **lst, t_dc_list *new)
{
	t_dc_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_dc_lstlast(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
}

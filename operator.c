/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/02 21:42:21 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_sa(t_info *info)
{
	int	tmp;

	tmp = info->list_a->next->content;
	info->list_a->next->content = info->list_a->next->next->content;
	info->list_a->next->next->content = tmp;
}

void	operate_sb(t_info *info)
{
	int	tmp;

	tmp = info->list_b->next->content;
	info->list_b->next->content = info->list_b->next->next->content;
	info->list_b->next->next->content = tmp;
}

void	operate_ss(t_info *info)
{
	operate_sa(info->list_a);
	operate_sb(info->list_b);
}

void	operate_pa(t_info *info)
{
	t_list	*tmp;

	if (!info->list_b)
		return ;
	tmp = info->list_b->next;
	info->list_b->next = info->list_b->next->next;
	ft_lstadd_back(&info->list_a, tmp);
}

void	operate_pb(t_info *info)
{
	t_list	*tmp;

	if (!info->list_a)
		return ;
	tmp = info->list_a->next;
	info->list_a->next = info->list_a->next->next;
	ft_lstadd_back(&info->list_b, tmp);
}

void	operate_ra(t_info *info)
{
	t_list	*first;
	t_list	*last;

	first = info->list_a->next;
	last = ft_lstlast(info->list_a);
	info->list_a->next = info->list_a->next->next;
	last->next = first;
	first->next = NULL;
}

void	operate_rb(t_info *info)
{
	t_list	*first;
	t_list	*last;

	first = info->list_b->next;
	last = ft_lstlast(info->list_b);
	info->list_b->next = info->list_b->next->next;
	last->next = first;
	first->next = NULL;
}

void	operate_rr(t_info *info)
{
	operate_ra(info->list_a);
	operate_rb(info->list_b);
}

void	operate_rra(t_info *info)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_two;

	first = info->list_a->next;
	last = ft_lstlast(info->list_a);
	last_two = info->list_a;
	while (last_two->next->next)
		last_two = last_two->next;
	info->list_a->next = last;
	last->next = first;
	last_two->next = NULL;
}

void	operate_rrb(t_info *info)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_two;

	first = info->list_b->next;
	last = ft_lstlast(info->list_b);
	last_two = info->list_b;
	while (last_two->next->next)
		last_two = last_two->next;
	info->list_b->next = last;
	last->next = first;
	last_two->next = NULL;
}

void	operate_rrr(t_info *info)
{
	operate_rra(info->list_a);
	operate_rrb(info->list_b);
}

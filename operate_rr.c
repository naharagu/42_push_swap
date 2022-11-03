/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 23:45:15 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	info->output[info->out_count] = RRA;
	info->out_count++;
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
	info->output[info->out_count] = RRB;
	info->out_count++;
}

void	operate_rrr(t_info *info)
{
	operate_rra(info);
	operate_rrb(info);
}

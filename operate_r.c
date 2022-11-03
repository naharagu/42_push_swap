/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 23:45:25 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_ra(t_info *info)
{
	t_list	*first;
	t_list	*last;

	first = info->list_a->next;
	last = ft_lstlast(info->list_a);
	info->list_a->next = info->list_a->next->next;
	last->next = first;
	first->next = NULL;
	info->output[info->out_count] = RA;
	info->out_count++;
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
	info->output[info->out_count] = RB;
	info->out_count++;
}

void	operate_rr(t_info *info)
{
	operate_ra(info);
	operate_rb(info);
}

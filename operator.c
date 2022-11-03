/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 22:15:23 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_sa(t_info *info)
{
	int	tmp;

	if (info->len_a < 2)
		return ;
	tmp = info->list_a->next->content;
	info->list_a->next->content = info->list_a->next->next->content;
	info->list_a->next->next->content = tmp;
	info->output[info->out_count] = SA;
	info->out_count++;
}

void	operate_sb(t_info *info)
{
	int	tmp;

	if (info->len_b < 2)
		return ;
	tmp = info->list_b->next->content;
	info->list_b->next->content = info->list_b->next->next->content;
	info->list_b->next->next->content = tmp;
	info->output[info->out_count] = SB;
	info->out_count++;
}

void	operate_ss(t_info *info)
{
	operate_sa(info);
	operate_sb(info);
}

void	operate_pa(t_info *info)
{
	t_list	*first;
	t_list	*second;

	if (info->len_b == 0)
		return ;
	first = info->list_b->next;
	second = info->list_b->next->next;
	if (info->len_b == 1)
		info->list_b->next = NULL;
	else
		info->list_b->next = second;
	if (info->len_a == 0)
		first->next = NULL;
	else
		first->next = info->list_a->next;
	info->list_a->next = first;
	info->output[info->out_count] = PA;
	info->out_count++;
	info->len_b--;
	info->len_a++;
}

void	operate_pb(t_info *info)
{
	t_list	*first;
	t_list	*second;

	if (info->len_a == 0)
		return ;
	first = info->list_a->next;
	second = info->list_a->next->next;
	if (info->len_a == 1)
		info->list_a->next = NULL;
	else
		info->list_a->next = second;
	if (info->len_b == 0)
		first->next = NULL;
	else
		first->next = info->list_b->next;
	info->list_b->next = first;
	info->output[info->out_count] = PB;
	info->out_count++;
	info->len_a--;
	info->len_b++;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_s_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 23:44:44 by naharagu         ###   ########.fr       */
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

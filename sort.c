/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:48:17 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 23:52:58 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_info *info)
{
	int		min_index;
	int		i;
	t_list	*tmp;

	while (info->len_a > 1)
	{
		min_index = get_min_index(info->list_a);
		prepare_pb(info, min_index);
		operate_pb(info);
		i = 1;
		tmp = info->list_a->next;
		while (i++ <= info->len_a)
			tmp = tmp->next;
		i = 1;
		tmp = info->list_b->next;
		while (i++ <= info->len_b)
			tmp = tmp->next;
	}
	while (info->len_b > 0)
		operate_pa(info);
}

void	sort_three(t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->list_a->next->content;
	second = info->list_a->next->next->content;
	third = info->list_a->next->next->next->content;
	if (first < second && first < third)
	{
		operate_sa(info);
		if (second > third)
			operate_ra(info);
	}
	else if (first > second && first > third)
	{
		operate_ra(info);
		if (second > third)
			operate_sa(info);
	}
	else if (first < second && second > third && first > third)
		operate_rra(info);
}
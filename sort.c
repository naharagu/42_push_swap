/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:48:17 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/08 21:19:45 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->list_a->next->content;
	b = info->list_a->next->next->content;
	c = info->list_a->next->next->next->content;
	if (a < b && a < c)
	{
		operate_sa(info);
		if (b > c)
			operate_ra(info);
	}
	else if (a > b && a > c)
	{
		operate_ra(info);
		if (b > c)
			operate_sa(info);
	}
	else if (a > b && b < c && a < c)
		operate_sa(info);
	else if (a < b && b > c && a > c)
		operate_rra(info);
}

void	sort_ten(t_info *info)
{
	int	min_index;

	while (info->len_a > 1)
	{
		if (check_sorted(info->list_a) == -1)
			break ;
		min_index = get_min_index(info->list_a);
		prepare_pb(info, min_index);
		operate_pb(info);
	}
	while (info->len_b > 0)
		operate_pa(info);
}

void	sort_big(t_info *info)
{
	int	i;
	int	j;
	int	digit;
	int	count;

	i = 0;
	digit = 0;
	while (i < info->len_all)
	{
		count = 0;
		while (count++ < info->len_all)
		{
			if ((info->list_a->next->content >> digit & 1) == 1)
				operate_ra(info);
			else
				operate_pb(info);
		}
		j = info->len_b;
		while (j--)
			operate_pa(info);
		if (check_sorted(info->list_a) == -1)
			return ;
		i++;
		digit++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:25:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/10/01 19:33:27by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void operate_sa(t_info *info)
{
	int tmp;

	tmp = info->list_a->content;
	info->list_a->content = info->list_a->next->content;
	info->list_a->next->content = tmp;
}

void operate_sb(t_info *info)
{
	int tmp;

	tmp = info->list_b->content;
	info->list_b->content = info->list_b->next->content;
	info->list_b->next->content = tmp;
}

void operate_ss(t_info *info)
{
	operate_sa(info->list_a);
	operate_sb(info->list_b);
}

// void operate_pa(t_info *info)
// {
// 	t_list tmp;

// 	if (!info->list_b)
// 		return;
// 	// tmp = info->list_b;
// 	// ft_lstadd_front(*info->list_b, info->list_a);
// 	// info->list_b = info->list_b->next;

// }

// void operate_ra(t_info *info)
// {
// 	t_list tmp;

// 	tmp = info->list_a->next;
// 	info->list_a->next = NULL;
// 	ft_lstadd_back(tmp, info->list_a);
// 	info->list_a->next = NULL;
// 	tmp = ft_lstlast(info->list_a);

// 	tmp.next = info->list_a;
// 	info->list_a->next = NULL;
// }


// void operate_rra(t_info *info)
// {
// 	t_list tmp;

// 	tmp = ft_lstlast(info->list_a);
// 	tmp.next = info->list_a;
// 	info->list_a->next = NULL;
// }
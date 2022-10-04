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
	operate_sa(info);
	operate_sb(info);
}

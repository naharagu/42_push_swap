/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:58:18 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/08 21:29:57 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void optimize_result(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->out_count - 1)
// 	{
// 		if (info->output[i] == PA && info->output[i + 1] == PB)

// 	}
// }

void	put_result(t_info *info)
{
	int	i;

	i = 0;
	while (info->output[i])
	{
		if (info->output[i] == PB && info->output[i + 1] == PA)
			i += 2;
		if (info->output[i] == SA)
			ft_putstr_fd("sa\n", 1);
		else if (info->output[i] == SB)
			ft_putstr_fd("sb\n", 1);
		else if (info->output[i] == PA)
			ft_putstr_fd("pa\n", 1);
		else if (info->output[i] == PB)
			ft_putstr_fd("pb\n", 1);
		else if (info->output[i] == RA)
			ft_putstr_fd("ra\n", 1);
		else if (info->output[i] == RB)
			ft_putstr_fd("rb\n", 1);
		else if (info->output[i] == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (info->output[i] == RRB)
			ft_putstr_fd("rrb\n", 1);
		i++;
	}
}

void	free_all(t_info *info)
{
	t_list	*tmp;

	while (info->list_a->next)
	{
		tmp = info->list_a->next;
		free(info->list_a);
		info->list_a = tmp;
	}
	while (info->list_b->next)
	{
		tmp = info->list_b->next;
		free(info->list_b);
		info->list_b = tmp;
	}
	free(info->list_a);
	free(info->list_b);
	if (info->output)
		free(info->output);
	free(info);
}

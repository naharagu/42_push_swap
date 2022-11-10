/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:14:40 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/10 10:04:44 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *list)
{
	int		i;
	int		min_value;
	int		min_index;
	t_list	*tmp;

	i = 1;
	min_value = INT_MAX;
	min_index = 0;
	tmp = list->next;
	while (tmp)
	{
		if (min_value > tmp->content)
		{
			min_value = tmp->content;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

void	prepare_pb(t_info *info, int min_index)
{
	if (min_index == 1)
		return ;
	else if (min_index <= info->len_a / 2 + 1)
	{
		while (min_index-- > 1)
			operate_ra(info);
	}
	else
	{
		while (min_index < info->len_a + 1)
		{
			operate_rra(info);
			min_index++;
		}
	}
}

void	push_swap(char **argv, int argc)
{
	t_info	*info;

	info = NULL;
	info = init_info(info);
	convert_to_list(argv, argc, info);
	if (check_sorted(info->list_a) == -1)
	{
		free_all(info);
		return ;
	}
	if (info->len_a == 2)
		operate_sa(info);
	else if (info->len_a == 3)
		sort_three(info);
	else if (info->len_a <= 10)
		sort_ten(info);
	else
		sort_big(info);
	put_result(info);
	free_all(info);
	return ;
}

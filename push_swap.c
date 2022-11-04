/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:14:40 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/04 10:11:15 by naharagu         ###   ########.fr       */
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
	else if (min_index <= info->len_a / 2)
	{
		while (min_index--)
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

void	push_swap(char **argv)
{
	t_info	*info;

	info = NULL;
	info = init_info(info);
	convert_to_list(argv, info);
	if (check_sorted(info->list_a) == -1)
		return ;
	if (info->len_a == 2)
		operate_sa(info);
	else if (info->len_a == 3)
		sort_three(info);
	else
		selection_sort(info);
	put_result(info);
	free_all(info);
	return ;
}

/* 	int i = 1;
	t_list *tmp = info->list_a->next;
	while (i <= info->len_a)
	{
		printf("a%d: %d\n", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
	i = 1;
	tmp = info->list_b->next;
	while (i <= info->len_b)
	{
		printf("b%d: %d\n", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_putchar_fd('\n', 2); */

/* 	int j = 1;
	t_list *tmp2 = info->list_a->next;
	while (j <= info->len_a)
	{
		printf("a%d: %d\n", j, tmp2->content);
		tmp2 = tmp2->next;
		j++;
	}
	j = 1;
	tmp2 = info->list_b->next;
	while (j <= info->len_b)
	{
		printf("b%d: %d\n", j, tmp2->content);
		tmp2 = tmp2->next;
		j++;
	}
	ft_putchar_fd('\n', 2); */
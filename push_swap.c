/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:18:04 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/02 21:44: by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	if (!info)
		exit(1);
	info->list_a = ft_lstnew(0);
	info->list_b = ft_lstnew(0);
	info->len_all = 0;
	info->len_a = 0;
	info->len_b = 0;
	info->output = malloc(sizeof(int *) * 5000);
	info->output[0] = 0;
	info->out_count = 0;
	return (info);
}

void	convert_to_list(char **argv, t_info *info)
{
	size_t	i;
	t_list	*tmp;
	int		value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(&info->list_a, tmp);
		i++;
	}
	info->len_all = i - 1;
	info->len_a = i - 1;
}

void	put_result(t_info *info)
{
	int	i;

	i = 0;
	while (info->output[i])
	{
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
	else if (min_index < info->len_a / 2)
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
		while (i <= info->len_a)
		{
			tmp = tmp->next;
			i++;
		}
		i = 1;
		tmp = info->list_b->next;
		while (i <= info->len_b)
		{
			tmp = tmp->next;
			i++;
		}
	}
	while (info->len_b > 0)
		operate_pa(info);
}

void	push_swap(char **argv)
{
	t_info	*info;

	info = NULL;
	info = init_info(info);
	convert_to_list(argv, info);
	if (info->len_a == 2)
		operate_sa(info);
	else
		selection_sort(info);
	put_result(info);
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
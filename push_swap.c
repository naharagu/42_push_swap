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
	info->list_a = NULL;
	ft_lstadd_back(&info->list_a, ft_lstnew(NULL));
	info->list_b = NULL;
	ft_lstadd_back(&info->list_b, ft_lstnew(NULL));
	info->len_all = 0;
	info->len_a = 0;
	info->len_b = 0;
	info->output = malloc(sizeof(int *));
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

void put_result(t_info *info)
{
	size_t i;

	i = 0;
	// ft_putstr_fd("put result\n", 1);
	// ft_putstr_fd(info->output[1], 1);
	while (info->output[i])
	{
		ft_putstr_fd("result putting...\n", 1);
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

int		get_min_index(t_list *list)
{
	int		i;
	int		min_value;
	int		min_index;
	t_list	*tmp;

	min_value = INT_MAX;
	i = 1;
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

void prepare_pb(t_info * info, int min_index)
{
	if (min_index == 1)
		operate_sa(info);
	else if (min_index < info->len_a / 2)
	{
		ft_putstr_fd("hey", 1);
		while (min_index--)
			operate_ra(info);
	}
	else
	{
		printf("lena: %d\n", info->len_a);
		while (min_index-- > 1)
		{
			ft_putstr_fd("heyhey\n", 1);
			operate_rra(info);
		}
	}
}

void	selection_sort(t_info * info)
{
	size_t	min_index;
	size_t	i;

	min_index = get_min_index(info->list_a);
	printf("min: %d\n", min_index);
	prepare_pb(info, min_index);

}

void	push_swap(char **argv)
{
	t_info	*info;

	info = init_info(info);
	convert_to_list(argv, info);
	// printf("size: %d\n", info->size);

	// if (info->size == 2)
	// 	operate_sa(info);
	// else if (info->size <= 10)
		// selection_sort(info);

	// operate_pb(info);
	operate_rra(info);

	printf("No. 0: %d\n", info->list_a->content);
	printf("No. 1: %d\n", info->list_a->next->content);
	printf("No. 2: %d\n", info->list_a->next->next->content);
	printf("No. 3: %d\n", info->list_a->next->next->next->content);
	// printf("No. 4: %d\n", info->list_a->next->next->next->next->content);
	// operate_pb(info);
	// printf("No. 0: %d\n", info->list_a->content);
	// printf("No. 1: %d\n", info->list_a->next->content);
	// printf("No. 2: %d\n", info->list_a->next->next->content);
	// printf("No. 3: %d\n", info->list_a->next->next->next->content);
	// printf("No. 4: %d\n", info->list_a->next->next->next->next->content);
	// printf("b No. 0: %d\n", info->list_b->content);
	// printf("b No. 1: %d\n", info->list_b->next->content);

	put_result(info);
	return ;
}

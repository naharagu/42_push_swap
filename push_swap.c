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
	info->size = 0;
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
	info->size = i - 1;
}

void put_result(t_info *info)
{
	size_t i;

	i = 0;

	while (info->output[i])
	{
		// ft_putstr_fd("g", 1);
		if (info->output[i] == SA)
			ft_putstr_fd("sa\n", 1);
		i++;
	}
}

int		get_min(t_list *list)
{
	int		min;
	t_list	*tmp;

	min = INT_MAX;
	tmp = list->next;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	selection_sort(t_info * info)
{
	size_t	min;
	size_t	i;


	// ft_putstr_fd("g\n", 2);
	min = get_min(info->list_a);
	printf("min: %d\n", min);

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
		selection_sort(info);

	// printf("No. 0: %d\n", info->list_a->content);
	// printf("No. 1: %d\n", info->list_a->next->content);
	// printf("No. 2: %d\n", info->list_a->next->next->content);
	// printf("No. 3: %d\n", info->list_a->next->next->next->content);
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

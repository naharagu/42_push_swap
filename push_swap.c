/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:18:04 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/02 21:36:49 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*initialize_info(t_info *info)
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
	printf("size is: %d\n", info->size);
	printf("No. 0: %d\n", info->list_a->content);
	printf("No. 1: %d\n", info->list_a->next->content);
	printf("No. 2: %d\n", info->list_a->next->next->content);
	printf("No. 3: %d\n", info->list_a->next->next->next->content);
	printf("No. 4: %d\n", info->list_a->next->next->next->next->content);
	operate_pb(info);
	printf("No. 0: %d\n", info->list_a->content);
	printf("No. 1: %d\n", info->list_a->next->content);
	printf("No. 2: %d\n", info->list_a->next->next->content);
	printf("No. 3: %d\n", info->list_a->next->next->next->content);
	// printf("No. 4: %d\n", info->list_a->next->next->next->next->content);
	printf("b No. 0: %d\n", info->list_b->content);
	printf("b No. 1: %d\n", info->list_b->next->content);
}

void	push_swap(char **argv)
{
	t_info	*info;

	info = initialize_info(info);
	convert_to_list(argv, info);
	// if (info->size < 10)
	// 	sort_small(info);
	// else
	// 	sort_big(info);
	return ;
}

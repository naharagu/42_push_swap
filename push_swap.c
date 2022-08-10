/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:18:04 by naharagu          #+#    #+#             */
/*   Updated: 2022/08/10 13:34:16 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*initialize_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	if (!info)
		exit(1);
	info->size = 0;
	info->list_a = NULL;
	info->list_b = NULL;
	return (info);
}

void convert_to_list(char **argv, t_info *info)
{
	size_t		i;
	t_dc_list	*tmp;
	int			value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		tmp = ft_dc_lstnew(value);
		ft_dc_lstadd_back(&info->list_a, tmp);
		i++;
	}
	tmp = ft_dc_lstlast(info->list_a);
	tmp->next = info->list_a;
	info->list_a->prev = tmp;
	// printf("%d\n", info->list_a->content);
	// printf("%d\n", info->list_a->next->content);
	// printf("%d\n", info->list_a->prev->content);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:18:04 by naharagu          #+#    #+#             */
/*   Updated: 2022/08/07 23:24:48 by naharagu         ###   ########.fr       */
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

void	push_swap(char **argv)
{
	char	**tmp;
	t_info	*info;

	info = initialize_info(info);
	info->size = ft_lstsize(info->list_a);
	if (info->size < 10)
		sort_small(info);
	else
		sort_big(info);
	return ;
}

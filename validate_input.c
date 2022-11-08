/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:59:11 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/08 21:31:25 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	if (!info)
		exit(EXIT_FAILURE);
	info->list_a = ft_lstnew(0);
	info->list_b = ft_lstnew(0);
	info->len_all = 0;
	info->len_a = 0;
	info->len_b = 0;
	info->output = malloc(sizeof(int) * 40000);
	if (!info->output)
		exit(EXIT_FAILURE);
	info->output[0] = 0;
	info->out_count = 0;
	return (info);
}

int	validate_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_int(argv[i]) == -1)
			return (-1);
		i++;
	}
	if (check_duplicate(argc, argv) == -1)
		return (-1);
	return (0);
}

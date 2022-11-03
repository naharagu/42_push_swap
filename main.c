/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:17:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 23:51:26 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2 && check_int(argv[1]) == 0)
		return (0);
	if (validate_arg(argc, argv) == -1)
		return (put_error());
	push_swap(argv);
	return (0);
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

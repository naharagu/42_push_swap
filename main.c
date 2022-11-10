/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:17:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/10 10:05:54 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2 && check_int(argv[1]) == 0)
		return (0);
	else if (argc == 2)
	{
		argv = ft_split_and_count(argv[1], ' ', &argc);
		flag = 1;
	}
	if (!argv)
		return (put_error());
	if (validate_arg(argc, argv) == -1)
	{
		if (flag)
			free_argv(argv, argc);
		return (put_error());
	}
	push_swap(argv, argc);
	if (flag)
		free_argv(argv, argc);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:17:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/08/09 21:08:27 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	validate_arg(int argc, char **argv)
{
	return (1);
}

int	is_sorted(char **argv)
{
	return (0);
}

int	main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// if (!validate_arg(argc, argv))
	// 	return (return_error());
	// if (!is_sorted(argv))
		push_swap(argv);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:17:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/04 21:58:55 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2 && check_int(argv[1]) == 0)
		return (0);
	if (validate_arg(argc, argv) == -1)
		return (put_error());
	push_swap(argv);
	// system("leaks push_swap");
	return (0);
}

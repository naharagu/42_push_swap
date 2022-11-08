/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:37:13 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/08 21:29:21 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		if (sign == 1 && (n > ((LONG_MAX - (*str - '0')) * sign) / 10))
			return (-1);
		else if (sign == -1 && (n < ((LONG_MIN - (*str - '0')) * sign) / 10))
			return (-1);
		n = n * 10 + ((*str++ - '0') * sign);
	}
	if (n > INT_MAX || n < INT_MIN)
		return (-1);
	return (0);
}

int	check_sorted_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (argv[i] > argv[i + 1])
			return (0);
	}
	return (-1);
}

int	check_sorted(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:17:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/03 22:39:10 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	check_int(char *str)
{
	int			i;
	long long	n;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (str[i])
			i++;
	}
	n = ft_atoi(str); //atoi is long long??
	if (n > INT_MAX || n < INT_MIN)
		return (-1);
	return (0);
}

int	check_sorted(t_info *info)
{
	t_list	*tmp;

	tmp = info->list_a->next;
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

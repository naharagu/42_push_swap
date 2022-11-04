/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:37:13 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/04 09:52:41 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_info *info)
{
	t_list	*tmp;

	while (info->list_a->next)
	{
		tmp = info->list_a->next;
		free(info->list_a);
		info->list_a = tmp;
	}
	while (info->list_b->next)
	{
		tmp = info->list_b->next;
		free(info->list_b);
		info->list_b = tmp;
	}
	free(info->list_a);
	free(info->list_b);
	if (info->output)
		free(info->output);
	free(info);
}

int	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

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

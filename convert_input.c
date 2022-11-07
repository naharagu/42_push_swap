/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:05:45 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/04 22:03:15y naharagu         ###   ########.fr       */
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
	info->output = malloc(sizeof(int) * 5000);
	if (!info->output)
		exit(EXIT_FAILURE);
	info->output[0] = 0;
	info->out_count = 0;
	return (info);
}

void	swap_int(int *x, int i, int j)
{
	int	tmp;

	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

int	*quick_sort_int(int *x, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = x[(left + right) / 2];
	while (1)
	{
		while (x[i] < pivot)
			i++;
		while (pivot < x[j])
			j--;
		if (i >= j)
			break ;
		swap_int(x, i, j);
		i++;
		j--;
	}
	if (left < i - 1)
		quick_sort_int(x, left, i - 1);
	if (j + 1 < right)
		quick_sort_int(x, j + 1, right);
	return (x);
}

void	compression(char **argv, t_info *info)
{
	int	i;
	int	j;
	int	*original;
	int	*sorted;

	original = malloc(sizeof(int) * (info->len_all));
	sorted = malloc(sizeof(int) * (info->len_all));
	if (!original || !sorted)
		exit(EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		original[i - 1] = ft_atoi(argv[i]);
		sorted[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	sorted = quick_sort_int(sorted, 0, info->len_all - 1);
	i = 0;
	// while (sorted[i])
	// {
	// 	printf("no %d is: %d \n", i, sorted[i]);
	// 	i++;
	// }

	i = 0;
	j = 0;
	while (sorted[i])
	{
		while (original[j])
		{
			if (sorted[i] == original[j])
			{
				original[j] = i;
				printf("no %d is: %d \n", i, original[j]);
				break;
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (original[i])
	{
		printf("no %d is: %d \n", i, original[i]);
		i++;
	}
	// free(original);
	free(sorted);
}

void	convert_to_list(char **argv, t_info *info)
{
	int		i;
	t_list	*tmp;
	int		value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(&info->list_a, tmp);
		i++;
	}
	info->len_all = i - 1;
	info->len_a = i - 1;
	compression(argv, info);
}

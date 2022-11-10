/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:05:45 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/10 09:58:51 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*compression_helper(int *sorted, int *compressed, char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (sorted[i - 1] == ft_atoi(argv[j]))
			{
				compressed[j - 1] = i;
				break ;
			}
			j++;
		}
		i++;
		j = 1;
	}
	return (compressed);
}

int	*compression(char **argv, int argc)
{
	int	i;
	int	*sorted;
	int	*compressed;

	sorted = malloc(sizeof(int) * 40000);
	compressed = malloc(sizeof(int) * 40000);
	if (!sorted || !compressed)
		exit(EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		sorted[i - 1] = ft_atoi(argv[i]);
		compressed[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	sorted = quick_sort_int(sorted, 0, argc - 2);
	compressed = compression_helper(sorted, compressed, argv, argc);
	compressed[argc- 1] = 0;
	free(sorted);
	return (compressed);
}

void	convert_to_list(char **argv, int argc, t_info *info)
{
	int		i;
	t_list	*tmp;
	int		*compressed;

	compressed = compression(argv, argc);
	i = 0;
	while (compressed[i])
	{
		tmp = ft_lstnew(compressed[i]);
		ft_lstadd_back(&info->list_a, tmp);
		i++;
	}
	free(compressed);
	info->len_all = i;
	info->len_a = i;
}

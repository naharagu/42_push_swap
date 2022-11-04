/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:54:50 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/04 09:31:57 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8

typedef struct s_info
{
	struct s_list	*list_a;
	struct s_list	*list_b;
	int				len_all;
	int				len_a;
	int				len_b;
	int				out_count;
	int				*output;
}					t_info;

void				push_swap(char **argv);
int					put_error(void);
int					check_int(char *str);
int					check_sorted(t_info *info);
int					check_duplicate(int argc, char **argv);
int					get_min_index(t_list *list);
void				prepare_pb(t_info *info, int min_index);
void				selection_sort(t_info *info);
void				sort_three(t_info *info);
void				operate_sa(t_info *info);
void				operate_sb(t_info *info);
void				operate_ss(t_info *info);
void				operate_pa(t_info *info);
void				operate_pb(t_info *info);
void				operate_ra(t_info *info);
void				operate_rb(t_info *info);
void				operate_rr(t_info *info);
void				operate_rra(t_info *info);
void				operate_rrb(t_info *info);
void				operate_rrr(t_info *info);
void				put_result(t_info *info);
void	free_all(t_info *info);

#endif

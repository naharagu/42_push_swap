/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:54:50 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/02 18:50:45 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

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
	int				size;
	int				*output;
}					t_info;

void		push_swap(char **argv);
void		operate_sa(t_info *info);
void		operate_sb(t_info *info);
void		operate_ss(t_info *info);

#endif

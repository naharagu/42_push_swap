/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:54:50 by naharagu          #+#    #+#             */
/*   Updated: 2022/08/10 14:18:45 by naharagu         ###   ########.fr       */
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

typedef struct s_dc_list
{
	int				content;
	struct s_dc_list	*next;
	struct s_dc_list	*prev;
}					t_dc_list;
typedef struct s_info
{
	struct s_dc_list	*list_a;
	struct s_dc_list	*list_b;
	int				size;
	int				*output;
}					t_info;

void		push_swap(char **argv);
t_dc_list	*ft_dc_lstnew(int content);
t_dc_list	*ft_dc_lstlast(t_dc_list *lst);
void		ft_dc_lstadd_back(t_dc_list **lst, t_dc_list *new);

#endif

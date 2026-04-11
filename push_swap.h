/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:08:35 by segribas          #+#    #+#             */
/*   Updated: 2026/04/11 20:32:51 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *b, t_stack *a);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				k_sort1(t_stack *a, t_stack *b);
void				k_sort2(t_stack *a, t_stack *b);
t_node				*new_node(int value);
void				push_node(t_stack *stack, t_node *node);
t_node				*pop_node(t_stack *stack);
int					find_max(t_stack *b);
int					stack_size(t_stack *stack);
bool				is_sorted(t_stack *stack);
int					square_root(int value);
long				ft_atol(const char *nptr);
int					parse(t_stack *a, int argc, char **argv);
void				assign_ranks(t_stack *a);
int					get_moves(t_stack *b);

void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				free_stack(t_stack *stack);
void				free_tokens(char **tokens, int argc);

#endif
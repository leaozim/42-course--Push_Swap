/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:36 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/09 17:49:08 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_libs/ft_libft/libft.h"	
# include "../my_libs/ft_printf/ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN_NO_SING 2147483648
# define INT_MIN -2147483648 
# define LESS '-'
# define PLUS '+'

typedef struct s_stack
{
	int	index;
	int	value;
}	t_stack;

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
	int		*index;
	int		*value;
	int		size_list;
	int		*copy_value;
}	t_push_swap;

void	initialize_variables(char **argv, int argc, t_push_swap *ps);
void	start_push_swap(t_push_swap *ps);
int		*convert_argv_in_int(char **argv, int argc);
int		*simplify_number(t_push_swap *ps, int size);
void	add_argumm_in_stack(t_push_swap *ps);

int		*merge_sort(int *arr, int len);
void	merge(int *result, int *left, int *right, int len);
int		*slice(int *arr, int start, int end);
void	*ft_memcpy_int(void *dest, const void *str, size_t n);

void	add_index(t_push_swap *ps, int *value, int *copy_value, int size);
int		get_index(t_list *a);
t_stack	*creat_content(int value, int index);

void	push(t_list **no1, t_list **no2, char *str);
void	rotate(t_list **no1, char *str);
void	swap(t_list **no1, char *str);
void	reverse_rotate(t_list **no1, char *str);
void	swap_stacks(t_list **no1, t_list **no2, char *str);
void	rotate_stacks(t_list **no1, t_list **no2, char *str);
void	reverse_rotate_stacks(t_list **no1, t_list **no2, char *str);

void	sort_two_elements(t_push_swap *ps);
void	sort_three_elements(t_push_swap *ps);
void	sort_five_elements(t_push_swap *ps);
void	sort_four_elements(t_push_swap *ps);
void	sort_many_elements(t_push_swap *ps);

void	error_checking(int argc, char **str);
int		check_ordering(t_list **parameters);
int		check_index_bigger_num(t_list **parameters);
int		check_index_lower_num(t_list **parameters);
int		check_size_int(char **str, int i);
int		check_is_digit_invalid(char **str, int argc);
void	check_one_node_exists(t_list **no1);
void	check_two_node_exists(t_list **no1, t_list **no2);

void	print_string(char *str);
void	destroy_push_swap(t_push_swap *ps);

#endif
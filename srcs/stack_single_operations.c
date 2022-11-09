/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_single_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:18:08 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 12:34:35 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list **no1, t_list **no2, char *str)
{
	t_list	*temp;

	check_one_node_exists(no1);
	temp = (*no1)->next;
	(*no1)->next = *no2;
	*no2 = *no1;
	*no1 = temp;
	print_string(str);
}

void	rotate(t_list **no1, char *str)
{
	t_list	*temp;

	check_one_node_exists(no1);
	temp = (*no1)->next;
	ft_lstlast((*no1))->next = *no1;
	(*no1)->next = NULL;
	*no1 = temp;
	print_string(str);
}

void	swap(t_list **no1, char *str)
{
	t_list	*temp;

	check_one_node_exists(no1);
	temp = (*no1)->next;
	(*no1)->next = (*no1)->next->next;
	temp->next = *no1;
	*no1 = temp;
	print_string(str);
}

void	reverse_rotate(t_list **no1, char *str)
{
	t_list	*temp;

	check_one_node_exists(no1);
	temp = ft_lstlast(*no1);
	ft_lst_before_last((*no1))->next = NULL;
	temp->next = *no1;
	*no1 = temp;
	print_string(str);
}

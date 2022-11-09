/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_many_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:29:30 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/07 19:12:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate_stacks(t_list **no1, t_list **no2, char *str)
{
	check_two_node_exists(no1, no2);
	reverse_rotate(no1, NULL);
	reverse_rotate(no2, NULL);
	ft_printf("%s\n", str);
}

void	rotate_stacks(t_list **no1, t_list **no2, char *str)
{
	check_two_node_exists(no1, no2);
	rotate(no1, NULL);
	rotate(no2, NULL);
	ft_printf("%s\n", str);
}

void	swap_stacks(t_list **no1, t_list **no2, char *str)
{
	check_two_node_exists(no1, no2);
	swap(no1, NULL);
	swap(no2, NULL);
	ft_printf("%s\n", str);
}

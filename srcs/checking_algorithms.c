/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_algorithms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:57:08 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/09 17:48:03 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_ordering(t_list **parameters)
{
	t_list	*no;
	t_stack	*no1;
	t_stack	*next_no;

	no = *parameters;
	while (no)
	{
		if (no->next)
		{
			no1 = (t_stack *)no->content;
			next_no = (t_stack *)no->next->content;
			if (no1->value > next_no->value)
				return (-1);
		}
		no = no->next;
	}
	return (0);
}

int	check_index_bigger_num(t_list **parameters)
{
	int		keep_big_index;
	int		big_num;
	int		i;
	t_stack	*no;
	t_list	*list;

	i = 0;
	keep_big_index = 0;
	list = *parameters;
	big_num = INT_MIN;
	while (list)
	{
		no = (t_stack *)list->content;
		if (no->value > big_num)
		{
			big_num = no->value;
			keep_big_index = i;
		}
		list = list->next;
		i++;
	}
	return (keep_big_index);
}

int	check_index_lower_num(t_list **parameters)
{
	int		keep_lower_index;
	int		lower_num;
	int		i;
	t_stack	*no;
	t_list	*list;

	i = 0;
	keep_lower_index = 0;
	list = *parameters;
	lower_num = INT_MAX;
	while (list)
	{
		no = (t_stack *)list->content;
		if (no->value < lower_num)
		{
			lower_num = no->value;
			keep_lower_index = i;
		}
		list = list->next;
		i++;
	}
	return (keep_lower_index);
}

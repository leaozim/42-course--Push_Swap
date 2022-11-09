/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:52:05 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/09 18:19:28 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_two_elements(t_push_swap *ps)
{
	if (!check_ordering(&ps->a))
		return ;
	swap(&ps->a, "sa");
}

void	sort_three_elements(t_push_swap *ps)
{
	int	bigger_num_posit;

	if (!check_ordering(&ps->a))
		return ;
	bigger_num_posit = check_index_bigger_num(&ps->a);
	if (bigger_num_posit == 0)
	{
		rotate(&ps->a, "ra");
		sort_two_elements(ps);
	}
	else if (bigger_num_posit == 1)
	{
		reverse_rotate(&ps->a, "rra");
		sort_two_elements(ps);
	}
	else
		sort_two_elements(ps);
}

void	sort_four_elements(t_push_swap *ps)
{
	int	low_num_posit;

	if (!check_ordering(&ps->a))
		return ;
	low_num_posit = check_index_lower_num(&ps->a);
	if (low_num_posit == 0)
	{
		push(&ps->a, &ps->b, "pb");
		sort_three_elements(ps);
		push(&ps->b, &ps->a, "pa");
	}
	else if (low_num_posit == 3)
	{
		reverse_rotate(&ps->a, "rra");
		push(&ps->a, &ps->b, "pb");
		sort_three_elements(ps);
		push(&ps->b, &ps->a, "pa");
	}
	else
	{
		rotate(&ps->a, "ra");
		sort_four_elements(ps);
	}
}

void	sort_five_elements(t_push_swap *ps)
{
	int	low_num_posit;

	if (!check_ordering(&ps->a))
		return ;
	low_num_posit = check_index_lower_num(&ps->a);
	if (low_num_posit == 0)
	{
		push(&ps->a, &ps->b, "pb");
		sort_four_elements(ps);
		push(&ps->b, &ps->a, "pa");
	}
	else if (low_num_posit > 0 && low_num_posit < 3)
	{
		rotate(&ps->a, "ra");
		sort_five_elements(ps);
	}
	else
	{
		reverse_rotate(&ps->a, "rra");
		sort_five_elements(ps);
	}	
}

void	sort_many_elements(t_push_swap *ps)
{
	int	size_in_bits;
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	size_in_bits = 0;
	while (ps->size_list >> max_bits++)
		size_in_bits++;
	i = 0;
	while (check_ordering(&ps->a) && i < size_in_bits)
	{
		j = 0;
		while (j < ps->size_list)
		{
			if ((get_index(ps->a) >> i) & 1)
				rotate(&ps->a, "ra");
			else
				push(&ps->a, &ps->b, "pb");
			j++;
		}
		while (ps->b)
			push(&ps->b, &ps->a, "pa");
		i++;
	}
}

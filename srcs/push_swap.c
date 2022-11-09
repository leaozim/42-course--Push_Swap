/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:14:53 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/09 18:20:00 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	error_checking(argc, argv);
	initialize_variables(argv, argc, &ps);
	simplify_number(&ps, argc);
	add_argumm_in_stack(&ps);
	start_push_swap(&ps);
	destroy_push_swap(&ps);
	return (0);
}

void	start_push_swap(t_push_swap *ps)
{
	if (ps->size_list == 2)
		sort_two_elements(ps);
	else if (ps->size_list == 3)
		sort_three_elements(ps);
	else if (ps->size_list == 4)
		sort_four_elements(ps);
	else if (ps->size_list == 5)
		sort_five_elements(ps);
	else if (ps->size_list > 5)
		sort_many_elements(ps);
}

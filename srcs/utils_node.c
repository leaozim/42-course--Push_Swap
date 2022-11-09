/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:32:15 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 12:34:29 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_one_node_exists(t_list **no1)
{
	if (!*no1)
		exit(1);
}

void	check_two_node_exists(t_list **no1, t_list **no2)
{
	if (!*no1 || !*no2)
		exit(12);
}

void	print_string(char *str)
{
	if (str)
		ft_printf("%s\n", str);
}

int	get_index(t_list *a)
{
	t_stack	*temp;

	temp = (t_stack *)a->content;
	return (temp->index);
}

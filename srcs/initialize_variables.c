/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:50:35 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 12:26:39 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	initialize_variables(char **argv, int argc, t_push_swap *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->size_list = argc - 1;
	ps->copy_value = ft_calloc(argc - 1, sizeof(int));
	ps->value = convert_argv_in_int(argv, argc);
}

int	*convert_argv_in_int(char **argv, int argc)
{
	int	*parameters;
	int	i;

	parameters = ft_calloc(argc - 1, sizeof(int));
	i = -1;
	while (++i < argc - 1)
		parameters[i] = ft_atoi(argv[i + 1]);
	return (parameters);
}

void	add_argumm_in_stack(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size_list)
		ft_lstadd_back(&ps->a, \
		ft_lstnew(creat_content(ps->value[i], ps->index[i])));
}

t_stack	*creat_content(int value, int index)
{
	t_stack	*content;

	content = ft_calloc(1, sizeof(t_stack));
	content->value = value;
	content->index = index;
	return (content);
}

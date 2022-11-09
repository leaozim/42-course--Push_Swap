/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:01 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 11:40:09 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_push_swap(t_push_swap *ps)
{
	ft_lstclear(&ps->a, free);
	free(ps->b);
	free(ps->index);
	free(ps->copy_value);
	free(ps->value);
}

void	*ft_memcpy_int(void *dest, const void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((int *)dest)[i] = ((int *)str)[i];
		i++;
	}
	return (dest);
}

void	add_index(t_push_swap *ps, int *value, int *copy_value, int size)
{
	int	i;
	int	j;

	i = 0;
	ps->index = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (value[i] == copy_value[j])
			{
				ps->index[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

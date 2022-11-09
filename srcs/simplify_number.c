/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:04:35 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 12:27:39 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*slice(int *arr, int start, int end)
{
	int	*result;
	int	i;

	i = start;
	result = (int *) malloc((end - start) * sizeof(int));
	while (i < end)
	{
		result[i - start] = arr[i];
		i++;
	}
	return (result);
}

void	add_value_in_result(int *result, int *value, int *index1, int *index2)
{
	result[*index1 + *index2] = value[*index1];
	*index1 += 1;
}

void	merge(int *result, int *left, int *right, int len)
{
	int	i;
	int	j;
	int	right_len;
	int	left_len;

	i = 0;
	j = 0;
	right_len = len - (len / 2);
	left_len = len / 2;
	while (i < left_len && j < right_len)
	{
		if (left[i] < right[j])
			add_value_in_result(result, left, &i, &j);
		else
			add_value_in_result(result, right, &j, &i);
	}
	while (i < left_len)
		add_value_in_result(result, left, &i, &j);
	while (j < right_len)
		add_value_in_result(result, right, &j, &i);
	free(left);
	free(right);
}

int	*merge_sort(int *arr, int len)
{
	int	*left;
	int	*right;

	if (len <= 1)
		return (0);
	left = slice(arr, 0, len / 2 + 1);
	right = slice(arr, len / 2, len);
	merge_sort(left, len / 2);
	merge_sort(right, len - (len / 2));
	merge(arr, left, right, len);
	return (arr);
}

int	*simplify_number(t_push_swap *ps, int size)
{
	ft_memcpy_int(ps->copy_value, ps->value, size - 1);
	merge_sort(ps->copy_value, size - 1);
	add_index(ps, ps->copy_value, ps->value, size - 1);
	return (ps->copy_value);
}

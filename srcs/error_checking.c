/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:52:13 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/08 12:44:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_size_int(char **str, int i)
{
	int				j;
	int				neg;
	unsigned int	value;

	j = 0;
	neg = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > 11)
			return (-1);
		if (ft_strlen(str[i]) >= 10)
		{
			if (str[i][j] == LESS || str[i][j] == PLUS)
			{
				if (str[i][j] == LESS)
					neg = 1;
				j++;
			}
			value = (unsigned int)ft_atoi(&str[i][j]);
			if (((value > INT_MIN_NO_SING) && neg) || (value > INT_MAX && !neg))
				return (-1);
		}
	i++;
	}
	return (0);
}

int	check_is_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{	
		if (ft_strlen(str[i]) == 1 && (str[i][0] == LESS || str[i][0] == PLUS))
			return (-1);
		else if (str[i][j] == LESS || str[i][j] == PLUS)
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (str[i][j])
			return (-1);
		j = 0;
		i++;
	}
	return (0);
}

int	check_repeated_number(char **str, int size_arg)
{
	int		j;
	int		i;

	i = 1;
	j = 1;
	while (str[i])
	{
		while (j < size_arg - 1)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j + 1]))
				return (-1);
			j++;
		}
		j = i + 1;
		i++;
	}
	return (0);
}

int	check_is_digit_invalid(char **str, int argc)
{
	int	i;

	i = 1;
	if (check_size_int(str, i) == -1)
		return (-1);
	else if (check_is_digit(str) == -1)
		return (-1);
	else if (check_repeated_number(str, argc) == -1)
		return (-1);
	return (0);
}

void	error_checking(int argc, char **str)
{
	if (argc == 1)
		exit (1);
	if (check_is_digit_invalid(str, argc))
	{
		ft_printf("Error\n");
		exit (1);
	}
}

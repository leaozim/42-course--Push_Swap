/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_before_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:06:56 by lade-lim          #+#    #+#             */
/*   Updated: 2022/11/01 14:51:36 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_before_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = (lst)->next;
	return (lst);
}

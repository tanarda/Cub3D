/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:51:24 by mehtan            #+#    #+#             */
/*   Updated: 2022/07/03 16:51:24 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*tmp;

	a = (*lst);
	while (a != NULL)
	{
		tmp = a->next;
		ft_lstdelone(a, del);
		a = tmp;
	}
	(*lst) = NULL;
}

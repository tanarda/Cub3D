/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:51:28 by mehtan            #+#    #+#             */
/*   Updated: 2022/07/03 16:51:28 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_calc(const char *str, int start, int len)
{
	int	max;

	max = ft_strlen(str);
	if (max - start >= len)
		return (len);
	else
		return (max - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	total;
	unsigned int	i;

	i = 0;
	if (!s || start > (unsigned int)ft_strlen(s) || len > 2147483647)
		return (ft_strdup(""));
	ss = (char *)malloc(sizeof(char) * (ft_malloc_calc(s, start, len) + 1));
	if (!ss)
		return (NULL);
	total = start + len;
	while (s[start] && start < total)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	return (ss);
}

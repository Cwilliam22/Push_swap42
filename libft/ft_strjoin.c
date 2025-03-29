/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:44:02 by apiscopo          #+#    #+#             */
/*   Updated: 2025/03/27 14:39:47 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		res[j++] = s1[i++];
	i = 0;
	while (i < len2)
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

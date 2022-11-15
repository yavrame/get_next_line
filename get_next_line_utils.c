/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:45:22 by emarion           #+#    #+#             */
/*   Updated: 2021/11/10 13:38:13 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*rs;

	rs = (char *)s;
	while (*rs)
	{
		if (*rs == c)
			return (rs);
		rs ++;
	}
	if (c == '\0')
		return (rs);
	return ((void *)0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	if (start > ft_strlen(s))
	{
		mem[i] = '\0';
		return (mem);
	}
	while ((char)s[start + i] != 0 && i < len)
	{
		mem[i] = (char)s[start + i];
		i ++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!(s1 && s2))
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!mem)
		return (NULL);
	while (++ i < len1)
		mem[i] = s1[i];
	i = -1;
	while (++ i < len2)
		mem[len1 + i] = s2[i];
	mem[len1 + i] = '\0';
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len ++;
	}
	return (len);
}

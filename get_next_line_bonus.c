/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:45:13 by emarion           #+#    #+#             */
/*   Updated: 2021/11/12 14:54:09 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	find_line(char **cache, char **line)
{
	size_t	l;
	char	*new_cache;

	*line = NULL;
	new_cache = NULL;
	l = 0;
	while ((*cache)[l] != '\n' && (*cache)[l] != '\0')
		l++;
	if ((*cache)[l] == '\n')
	{
		*line = ft_substr(*cache, 0, (l + 1));
		new_cache = ft_strdup(&(*cache)[l + 1]);
	}
	else if (**cache)
		*line = ft_strdup(*cache);
	free(*cache);
	*cache = new_cache;
}

void	reader(int fd, char **buf, char **line, char **cache)
{
	int		buf_pointer;
	char	*temp_cache;

	while ((!ft_strchr(*cache, '\n')))
	{
		buf_pointer = read(fd, *buf, BUFFER_SIZE);
		if (buf_pointer == 0)
			break ;
		(*buf)[buf_pointer] = '\0';
		temp_cache = *cache;
		*cache = ft_strjoin(temp_cache, *buf);
		free(temp_cache);
	}
	free(*buf);
	*buf = NULL;
	find_line(cache, line);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	char			*check;
	static char		*cache[FDM];

	check = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, check, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!cache[fd])
		cache[fd] = ft_strdup("");
	reader(fd, &buf, &line, &cache[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HK       <HK@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:21:57 by HK                 #+#    #+#            */
/*   Updated: 2022/11/16 16:02:14 by HK                ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd, char *remaining)
{
	char	*buffer;
	int		red;

	red = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (red && !find_new_line(remaining))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(buffer);
			free(remaining);
			return (0);
		}
		buffer[red] = 0;
		remaining = ft_strjoin(remaining, buffer);
	}
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remaining = read_from_file(fd, remaining);
	if (!remaining)
		return (0);
	line = ft_get_line(remaining);
	remaining = ft_save_remaining(remaining);
	return (line);
}

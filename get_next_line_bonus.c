/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:27:36 by ibenaait          #+#    #+#             */
/*   Updated: 2022/11/16 15:52:11 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*remaining[OPEN_MAX];
	int			flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remaining[fd] = read_from_file(fd, remaining[fd]);
	if (!remaining[fd])
		return (0);
	line = ft_get_line(remaining[fd]);
	remaining[fd] = ft_save_remaining(remaining[fd], &flag);
	if (!remaining[fd] && flag)
		return (0);
	return (line);
}

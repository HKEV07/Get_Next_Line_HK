/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HK       <HK@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:21:57 by HK                 #+#    #+#            */
/*   Updated: 2022/11/16 16:02:14 by HK                ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_new_line(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i++] == '\n')
				return (1);
		}
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		*s1 = 0;
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
		str[j++] = s1[i++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

char	*ft_get_line(char *remaining)
{
	char	*line;
	int		i;

	i = 0;
	if (!remaining[i])
		return (0);
	while (remaining[i] && remaining[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (remaining[i] && remaining[i] != '\n')
	{
		line[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_save_remaining(char *remaining)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (!remaining[i])
	{
		free(remaining);
		return (0);
	}
	s = malloc(ft_strlen(remaining) + 1 - i);
	if (!s)
	{
		free(remaining);
		return (0);
	}
	j = 0;
	while (remaining[++i])
		s[j++] = remaining[i];
	s[j] = 0;
	free(remaining);
	return (s);
}

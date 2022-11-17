/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:21:40 by ibenaait          #+#    #+#             */
/*   Updated: 2022/11/15 22:02:54 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_from_file(int fd, char *remaining);
char	*ft_strjoin(char *remaining, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *remaining);
char	*ft_save_remaining(char *remaining, int *flag);
int		find_new_line(char *str);

#endif

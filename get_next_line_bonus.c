/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:57 by erpiana           #+#    #+#             */
/*   Updated: 2023/11/29 00:41:09 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*rest_file(char *file)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!(file[i]))
	{
		free(file);
		return (NULL);
	}
	if (file[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(file) + 1 - i));
	if (!rest)
		return (NULL);
	j = 0;
	while (file[i] != '\0')
		rest[j++] = file[i++];
	rest[j] = '\0';
	free(file);
	return (rest);
}

static char	*cut_line(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (!*file)
		return (NULL);
	while (file[i] != '\n' && file[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i])
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_file(char *line, int fd)
{
	int		flag;
	char	*buffer;

	flag = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (flag > 0 && !ft_strchr(line, '\n'))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file[fd] = read_file(file[fd], fd);
	if (!file[fd])
		return (NULL);
	line = cut_line(file[fd]);
	file[fd] = rest_file(file[fd]);
	return (line);
}

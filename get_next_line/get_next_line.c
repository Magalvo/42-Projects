/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:39:57 by dde-maga          #+#    #+#             */
/*   Updated: 2023/11/17 18:22:33 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, buffer, BUFFER_SIZE) <= 0 || BUFFER_SIZE <= 0)
	{
		while (buffer[i])
			buffer[i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		ft_clean_buf(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
} 
/* char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			count;

	count = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (NULL);
		if (count == 0)
			return (line);
		buffer[count] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (buffer[count - 1] == '\n')
			break;
	}
	return (line);
}
 */
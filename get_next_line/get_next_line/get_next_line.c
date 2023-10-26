/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:39:57 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/26 12:45:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// Read from fd and add to linked list
	read_and_stash(fd, &stash, &readed);
	if (!stash)
		return (NULL);
	// Extract from stash to line 
	
	// Clean up stash
	
	return (line);
}

void read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buffer;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	while (!found_newline(*stash) && *readed_ptr != 0)
	{
		*readed_ptr = read(fd, buffer, BUFFER_SIZE);
		if (!*readed_ptr || *readed_ptr == 0 || *readed_ptr == -1)
		{
			free(buffer);
			return ;
		}
			return ;
		buffer[*readed_ptr] = '\0';
	}
}
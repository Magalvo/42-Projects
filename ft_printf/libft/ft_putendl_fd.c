/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:42 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/21 19:19:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s && fd > 0)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	write(fd, "\n", 1);
}

/* #include <fcntl.h>
int	main()
{
	int	fd;

	fd = open("./txt/testputnb.txt", O_WRONLY | O_CREAT | O_TRUNC, 0642);
	ft_putendl_fd("test", fd);
	close(fd);
	return (0);
} */
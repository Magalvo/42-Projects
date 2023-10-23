/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:27:02 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/21 14:46:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
	return (1);
}

/* int main()
{
	ft_putchar_fd('a', 1);
} */
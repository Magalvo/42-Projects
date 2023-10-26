/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:49 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/18 15:04:28 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_verify(char *base)
{
	int		i;
	int		len;
	int		j;
	char	a[127];

	i = 0;
	len = ft_strlen(base);
	if (!(base[0] || base[1]))
		return (0);
	while (i < len)
	{
		j = base[i] + '0';
		if (!(a[base[j]]))
			a[base[j]] = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbl;
	char		ch;
	int			len;

	len = ft_strlen(base);
	nbl = nbr;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	if (nbl >= len)
		ft_putnbr_base(nbl / len, base);
	ch = base[nbl % len];
	write(1, &ch, 1);
}

/* int main()
{
	ft_putnbr_base(-256, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(-256, "012345678&*)9ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-256, "01");
	write(1, "\n", 1);
	return (0);    
} */
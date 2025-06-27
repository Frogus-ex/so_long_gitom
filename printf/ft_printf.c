/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:39:41 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 14:39:41 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mixer(va_list ap, const char ptr)
{
	int		count;

	count = 0;
	if (ptr == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (ptr == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (ptr == '%')
		count += ft_putchar('%');
	else if (ptr == 'd' || ptr == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (ptr == 'u')
		count += ft_unsigned(va_arg(ap, int));
	else if (ptr == 'x')
		count += ft_puthex_min(va_arg(ap, int));
	else if (ptr == 'X')
		count += ft_puthex_maj(va_arg(ap, int));
	else if (ptr == 'p')
		count += ft_putaddr(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *ptr, ...)
{
	int		i;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			count += ft_mixer(ap, ptr[i + 1]);
			i++;
		}
		else
			count += ft_putchar(ptr[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

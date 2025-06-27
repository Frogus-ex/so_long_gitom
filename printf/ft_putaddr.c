/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:39:52 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 14:39:52 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_printaddr(const unsigned long n)
{
	if (n >= 16)
		return (ft_printaddr(n / 16) + ft_printaddr(n % 16));
	else
		return (ft_putchar("0123456789abcdef"[n]));
}

size_t	ft_putaddr(void *addr)
{
	if (!addr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_printaddr((uintptr_t)addr));
}

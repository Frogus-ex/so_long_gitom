/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:40:06 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 14:40:06 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_maj(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_maj(n / 16);
	count += ft_putchar(str[n % 16]);
	return (count);
}

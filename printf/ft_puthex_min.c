/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:40:21 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 14:40:21 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_min(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_min(n / 16);
	count += ft_putchar(str[n % 16]);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:38:03 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 14:38:03 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	char	result;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned(n / 10);
	result = n % 10 + '0';
	count += ft_putchar(result);
	return (count);
}
// #include <stdio.h>

// int	main ()
// {
// 	int	n;

// 	n = -200;
// 	ft_unsigned(n);
// 	printf("%u\n", n);
// }
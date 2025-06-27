/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:18:35 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/12 11:18:35 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_unsigned(unsigned int n);
int		ft_putchar(char c);
int		ft_printf(const char *ptr, ...);
size_t	ft_putaddr(void *addr);
int		ft_putnbr(int n);
int		ft_puthex_min(unsigned int n);
int		ft_puthex_maj(unsigned int n);

#endif
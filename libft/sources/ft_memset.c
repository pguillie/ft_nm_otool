/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:58:25 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 20:05:28 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void *
ft_memset(void *s, int c, size_t n)
{
	uint8_t	*str;

	str = (uint8_t *)s;
	while (n--)
		str[n] = c;
	return (s);
}

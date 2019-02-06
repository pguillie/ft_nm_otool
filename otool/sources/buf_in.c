/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:41:55 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 16:25:32 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void
buf_in(struct macho_info *macho, const char *str, size_t n)
{
	if (macho->buf_index + n > BUF_SIZE)
		buf_out(macho);
	if (n > BUF_SIZE) {
		write(1, str, n);
	} else {
		ft_memcpy(macho->buf + macho->buf_index, str, n);
		macho->buf_index += n;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:39:51 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/01 15:36:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
buf_out(struct macho_info *macho)
{
	if (macho->buf_index) {
		write(1, macho->buf, macho->buf_index);
		macho->buf_index = 0;
	}
}

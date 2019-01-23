/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_load_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:43:49 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/22 11:41:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct load_command *
get_load_command(void *ptr, struct macho_info macho)
{
	struct load_command	*lc;

	if (ptr + sizeof(struct load_command) > macho.ptr + macho.size)
		return (NULL);
	lc = (struct load_command *)ptr;
	if (macho.is_rev) {
		lc->cmd = OSSwapConstInt32(lc->cmd);
		lc->cmdsize = OSSwapConstInt32(lc->cmdsize);
	}
	dprintf(2, "=== LOAD_COMMAND ===\n");
	dprintf(2, "%.8x\n", lc->cmd);
	dprintf(2, "%.8x\n", lc->cmdsize);
	if (ptr + lc->cmdsize > macho.ptr + macho.size)
		return (NULL);
	return (lc);
}

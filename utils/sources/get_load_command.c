/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_load_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:43:49 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:15:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stddef.h>

# define REV_BYTE_ORDER 1

struct load_command *
get_load_command(void *ptr, void *boundary, char swap)
{
	struct load_command	*lc;
	int			rev;

	rev = (uint32_t)boundary & REV_BYTE_ORDER; //64
	boundary = (uint32_t)boundary & ~REV_BYTE_ORDER; //64
	if (ptr + sizeof(struct load_command) > boundary)
		return (NULL);
	lc = (struct load_command *)ptr;
	if (swap) {
		lc->cmd = OSSwapConstInt32(lc->cmd);
		lc->cmdsize = OSSwapConstInt32(lc->cmdsize);
	}
	if (ptr + lc->cmdsize > boundary)
		return (NULL);
	return (lc);
}

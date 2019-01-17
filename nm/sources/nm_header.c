/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:11:15 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 17:45:54 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stdlib.h>

# define REV_BYTE_ORDER 1

int
nm_mach_header(void *ptr, void *boundary);


int
nm_header(void *ptr, void *boundary)
{
	unsigned int	magic;
	int		ret;

	magic = *(unsigned int *)ptr;
	if (magic == MH_MAGIC)
		ret = nm_mach_header(ptr, boundary);
	else if (magic == MH_CIGAM)
		ret = nm_mach_header(ptr, (uint32_t)boundary | REV_BYTE_ORDER);
	else
		return (EXIT_FAILURE);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_mach_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:23:28 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:19:44 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct mach_header *
get_mach_header(void *ptr, void *boundary);

struct load_command *
get_load_command(void *ptr, void *boundary);


static int
nm_mach_header_segment(void *ptr, void *boundary, uint32_t ncmds)
{

}

int
nm_mach_header(void *ptr, void *boundary)
{
	struct mach_header	*header;
	struct load_command	*lc;
	uint32_t		ncmds;
	int			sectn[3];

	if ((header = get_mach_header(ptr, boundary)) == NULL)
		return (EXIT_FAILURE);
	lc = ptr + sizeof(struct mach_header);
	if ((lc = get_load_command(lc, boundary)) == NULL)
		return (EXIT_FAILURE);
	ncmds = header->ncmds;
}

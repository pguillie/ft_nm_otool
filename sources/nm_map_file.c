/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_map_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 16:42:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_nm.h"

int
nm_map_file(char const *file)
{
	struct macho_info	macho;
	struct stat		buf;
	int			fd;
	int			ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if (fstat(fd, &buf) < 0) {
		close(fd);
		return (-1);
	}
	macho.ptr = mmap(NULL, buf.st_size,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE, fd, 0);
	close(fd);
	if (macho.ptr == MAP_FAILED)
		return (-1);
	macho.size = buf.st_size;
	ret = nm_check_header(macho);
	if (munmap(macho.ptr, buf.st_size) < 0)
		return (-1);
	return (ret);
}

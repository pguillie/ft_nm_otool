/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_map_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:42:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_nm.h"

static int
nm_init_macho(void *ptr, uint64_t size, const char *file, int multi_args)
{
	struct macho_info macho;

	macho.ptr = ptr;
	macho.size = size;
	macho.file = file;
	macho.buf_index = 0;
	if (multi_args) {
		buf_in(&macho, "\n", 1);
		buf_in(&macho, file, ft_strlen(file));
		buf_in(&macho, ":\n", 2);
	}
	return (nm_check_header(&macho));
}

static int
open_error(const char *file)
{
	if (access(file, F_OK) < 0)
		nm_error(file, E_NOENT);
	else if (access(file, R_OK) < 0)
		nm_error(file, E_PERM);
	else
		nm_error(file, E_UNDF);
	return (1);
}


int
nm_map_file(const char *file, int multi_args)
{
	void *ptr;
	struct stat buf;
	int fd;
	int ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (open_error(file));
	if (fstat(fd, &buf) < 0) {
		close(fd);
		return (-1);
	}
	ptr = mmap(NULL, buf.st_size,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE, fd, 0);
	close(fd);
	if (ptr == MAP_FAILED)
		return (-1);
	if ((ret = nm_init_macho(ptr, buf.st_size, file, multi_args)) > 0)
		nm_error(file, (ret == 1 ? E_TRUNC : E_NVALID));
	if (munmap(ptr, buf.st_size) < 0)
		return (-1);
	return (ret > 1 ? 1 : ret);
}

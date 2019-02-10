/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 17:33:44 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_otool.h"

static int
otool_init_macho(void *ptr, uint64_t size, const char *file, int opt)
{
	struct macho_info macho;

	macho.ptr = ptr;
	macho.size = size;
	macho.file = file;
	macho.buf_index = 0;
	macho.opt = opt;
	buf_in(&macho, file, ft_strlen(file));
	buf_in(&macho, ":\n", 2);
	return (otool_check_header(&macho));
}

static int
open_error(const char *file)
{
	if (access(file, F_OK) < 0)
		otool_error(file, E_NOENT);
	else if (access(file, R_OK) < 0)
		otool_error(file, E_PERM);
	else
		otool_error(file, E_UNDF);
	return (1);
}

static int
mmap_error(const char *file, struct stat buf)
{
	if (buf.st_size == 0)
		otool_error_stdout(file, E_NVALID);
	else if (((buf.st_mode) & S_IFMT) == S_IFDIR)
		otool_error(file, E_ISDIR);
	else
		return (-1);
	return (1);
}

int
otool_map_file(const char *file, int opt)
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
		return (mmap_error(file, buf));
	ret = otool_init_macho(ptr, buf.st_size, file, opt);
	if (ret == 1)
		otool_error(file, E_TRUNC);
	else if (ret > 1)
		otool_error_stdout(file, E_NVALID);
	if (munmap(ptr, buf.st_size) < 0)
		return (-1);
	return (ret > 1 ? 1 : ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:06:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 17:36:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int nm_header(void *ptr, void *boundary);

int
nm_file(const char *file)
{
	int		fd;
	struct stat	buf;
	void		*ptr;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (fstat(fd, &buf) < 0) {
		close(fd);
		return (EXIT_FAILURE);
	}
	ptr = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (ptr == MAP_FAILED)
		return (EXIT_FAILURE);
	ret = nm_header(ptr, ptr + buf.st_size);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:11:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/31 18:12:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHO_INFO_H
# define MACHO_INFO_H

# include <stdint.h>

/*
** Should fit in a `uint16_t'
*/
# define BUF_SIZE 1024

// /*
// ** 8 and 16 bytes containing space (` ', 0x20) characters
// */
// # define SPACE_ADDR	(uint32_t)0x2020202020202020
// # define SPACE_ADDR_64	(uint64_t)0x20202020202020202020202020202020

struct	macho_info {
	const char	*file;
	void		*ptr;
	uint64_t	size;
	char		buf[BUF_SIZE];
	uint16_t	buf_index;
	uint8_t		is_rev;
	uint8_t		text_sect;
	uint8_t		data_sect;
	uint8_t		bss_sect;
};

void
buf_out(struct macho_info *macho);

void
buf_in(struct macho_info *macho, const char *str, size_t n);

#endif /* MACHO_INFO_H */

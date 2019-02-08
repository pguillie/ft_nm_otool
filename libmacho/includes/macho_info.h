/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:45:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 15:45:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHO_INFO_H
# define MACHO_INFO_H

/*
** Should fit in a `uint16_t'
*/
# define BUF_SIZE 1024

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
	cpu_type_t	cpu;
};

#endif

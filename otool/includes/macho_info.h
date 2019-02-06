/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:11:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 21:25:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHO_INFO_H
# define MACHO_INFO_H

# include <stdint.h>

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
	cpu_type_t	cpu;
};

void
buf_out(struct macho_info *macho);

void
buf_in(struct macho_info *macho, const char *str, size_t n);

#endif /* MACHO_INFO_H */

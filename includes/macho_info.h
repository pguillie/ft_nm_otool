/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:11:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:12:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHO_INFO_H
# define MACHO_INFO_H

# include <stdint.h>

# define BUF_SIZE 512

struct	macho_info {
	void		*ptr;
	uint64_t	size;
	char		buf[BUF_SIZE]; //api call to fill
	uint8_t		buf_index;
	uint8_t		is_rev;
	uint8_t		text_sect;
	uint8_t		data_sect;
	uint8_t		bss_sect;
};

//api ---------------------------------^
//...

#endif /* MACHO_INFO_H */

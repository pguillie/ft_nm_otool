/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:38:15 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:46:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHO_UTILS_H
# define MACHO_UTILS_H

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>

struct load_command	get_load_command(void *ptr);//

#endif /* MACHO_UTILS_H */

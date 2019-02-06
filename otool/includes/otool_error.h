/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:08:14 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 23:24:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_ERROR_H
# define OTOOL_ERROR_H

/*
** Same output as /usr/bin/nm
*/
# define E_UNDF ": Undefined error"
# define E_NOENT ": No such file or directory"
# define E_PERM ": Permission denied"
# define E_ISDIR ": Is a directory"
# define E_NVALID ": is not an object file"
# define E_TRUNC ": truncated or malformed file"

void
otool_error(const char *file, const char *msg);

void
otool_error_stdout(const char *file, const char *msg);

#endif /* OTOOL_ERROR_H */

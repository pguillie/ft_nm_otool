/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:08:14 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 23:25:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_ERROR_H
# define NM_ERROR_H

/*
** Same output as /usr/bin/nm
*/
# define E_UNDF ": Undefined error."
# define E_NOENT ": No such file or directory."
# define E_PERM ": Permission denied."
# define E_ISDIR ": Is a directory."
# define E_NVALID " The file was not recognized as a valid object file\n"
# define E_TRUNC " truncated or malformed file\n"

void
nm_error(const char *file, const char *msg);

#endif /* NM_ERROR_H */

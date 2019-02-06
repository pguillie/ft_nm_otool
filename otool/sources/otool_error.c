/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:59:32 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 22:50:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void
otool_error(const char *file, const char *msg)
{
	write(2, "ft_otool: ", 10);
	if (file) {
		write(2, "'", 1);
		write(2, file, ft_strlen(file));
		write(2, "'", 1);
	}
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void
otool_error_stdout(const char *file, const char *msg)
{
	if (file)
		write(1, file, ft_strlen(file));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:33:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 19:12:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void
otool_usage(void)
{
	ft_putstr("usage: ft_otool <options> file ...\n");
	ft_putstr("\t-d Display the contents of the (__DATA,__data)"
		" section.\n");
	ft_putstr("\t-t Display the contents of the (__TEXT,__text)"
		" section.\n");
}

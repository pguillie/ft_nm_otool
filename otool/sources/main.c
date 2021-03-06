/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 17:29:45 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int
main(int argc, const char *argv[])
{
	int ret;
	int err;
	int opt;

	if (!((opt = otool_options(&argc, &argv)) > 0)) {
		otool_usage();
		return (1);
	}
	if (argc == 1)
		return (otool_map_file("a.out", opt));
	else if (argc == 2)
		return (otool_map_file(argv[1], opt));
	ret = 0;
	while (argc-- > 1) {
		err = otool_map_file(*++argv, opt);
		if (err < 0)
			return (-1);
		if (err)
			ret = 1;
	}
	return (ret);
}

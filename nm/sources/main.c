/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 21:14:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
main(int argc, const char *argv[])
{
	int ret;
	int err;
	int opt;

	if ((opt = nm_options(&argc, &argv)) < 0)
		return (1);
	if (argc == 1)
		return (nm_map_file("a.out", opt, 0));
	else if (argc == 2)
		return (nm_map_file(argv[1], opt, 0));
	ret = 0;
	while (argc-- > 1) {
		err = nm_map_file(*++argv, opt, 1);
		if (err < 0)
			return (-1);
		if (err)
			ret = 1;
	}
	return (ret);
}

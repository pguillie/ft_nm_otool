/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:56:57 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 22:38:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void
invalid_option(int opt)
{
	write(2, "ft_nm: illegal option -- ", 25);
	write(2, &opt, 1);
	write(2, "\n", 1);
}

static int
option_value(char c)
{
	if (c == 'g')
		return (OPT_G);
	else if (c == 'n')
		return (OPT_N);
	else if (c == 'p')
		return (OPT_P);
	else if (c == 'r')
		return (OPT_R);
	else if (c == 'u')
		return (OPT_U);
	else if (c == 'U')
		return (OPT_NU);
	else if (c == 'j')
		return (OPT_J);
	return (0);
}

static int
nm_get_option(const char *arg)
{
	int opt;
	int ret;
	size_t i;

	if (ft_strcmp(arg, "-help") == 0 || ft_strcmp(arg, "--help") == 0) {
		nm_usage();
		return (-1);
	}
	if (arg[1] == '-' && arg[2] == '\0')
		return (0);
	opt = 0;
	i = 1;
	while (arg[i]) {
		ret = option_value(arg[i]);
		if (ret) {
			opt |= ret;
		} else {
			invalid_option(arg[i]);
			nm_usage();
			return (-1);
		}
		i++;
	}
	return (opt);
}

int
nm_options(int *ac, const char ***av)
{
	int opt;
	int ret;
	int i;

	opt = 0;
	i = 1;
	while (*ac > 1) {
		if ((*av)[i][0] != '-')
			break ;
		if ((ret = nm_get_option((*av)[i])) < 0)
			return (-1);
		(*ac)--;
		(*av)++;
		if (ret == 0)
			break ;
		opt |= ret;
	}
	return (opt);
}

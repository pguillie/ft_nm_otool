/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:27:41 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 19:11:36 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void
invalid_option(int opt)
{
	write(2, "ft_otool: illegal option -- ", 28);
	write(2, &opt, 1);
	write(2, "\n", 1);
}

static int
option_value(char c)
{
	if (c == 'd')
		return (OPT_D);
	else if (c == 't')
		return (OPT_T);
	return (0);
}

static int
otool_get_option(const char *arg)
{
	int opt;
	int ret;
	int i;

	if (ft_strcmp(arg, "-help") == 0 || ft_strcmp(arg, "--help") == 0)
		return (-1);
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
			return (-1);
		}
		i++;
	}
	return (opt);
}

int
otool_options(int *ac, const char ***av)
{
	int opt;
	int ret;
	int i;

	opt = 0;
	i = 1;
	while (*ac > 1) {
		if ((*av)[i][0] != '-')
			break ;
		if ((ret = otool_get_option((*av)[i])) < 0)
			return (-1);
		(*ac)--;
		(*av)++;
		if (ret == 0)
			break ;
		opt |= ret;
	}
	return (opt);
}

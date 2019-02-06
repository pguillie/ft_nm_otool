/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:14:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/31 19:15:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_TYPE_H
# define CPU_TYPE_H

# include <mach/machine.h>

struct cpu_info {
	cpu_type_t	type;
	char		*str;
};

#endif /* CPU_TYPE_H */

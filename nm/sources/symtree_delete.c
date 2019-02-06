/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:57:47 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:30:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
symtree_delete(struct symtree *node)
{
	if (node) {
		symtree_delete(node->left);
		symtree_delete(node->right);
		free(node);
	}
}

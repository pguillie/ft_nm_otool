/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_fat_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 17:30:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static ssize_t
get_arch(struct fat_arch *arch_hdr, uint32_t narch,
	const struct macho_info *macho)
{
	uint32_t i;

	i = 0;
	while (i < narch) {
		if (get_fat_arch(arch_hdr, macho) == NULL)
			return (-1);
		if (arch_hdr->cputype == CPU_TYPE_X86_64)
			break ;
		arch_hdr++;
		i++;
	}
	return (i);
}

static char *
otool_cpu_type(cpu_type_t cputype)
{
	static struct cpu_info cpu[15] = {
		{CPU_TYPE_ANY, "any"},
		{CPU_TYPE_VAX, "vax"},
		{CPU_TYPE_MC680x0, "mc680x0"},
		{CPU_TYPE_X86, "x86"},
		{CPU_TYPE_I386, "i386"},
		{CPU_TYPE_X86_64, "x86_64"},
		{CPU_TYPE_MC98000, "mc98000"},
		{CPU_TYPE_HPPA, "hppa"},
		{CPU_TYPE_ARM, "arm"},
		{CPU_TYPE_ARM64, "arm64"},
		{CPU_TYPE_MC88000, "mc88000"},
		{CPU_TYPE_SPARC, "sparc"},
		{CPU_TYPE_I860, "i860"},
		{CPU_TYPE_POWERPC, "ppc"},
		{CPU_TYPE_POWERPC64, "ppc64"}
	};
	size_t i;

	i = sizeof(cpu) / sizeof(cpu[0]);
	while (i--)
		if (cpu[i].type == cputype)
			return (cpu[i].str);
	return ("");
}

static int
otool_fat_arch(struct fat_arch *arch_hdr, const struct macho_info *macho,
	int multi_arch)
{
	struct macho_info arch;
	char *cpu;

	arch.ptr = macho->ptr + arch_hdr->offset;
	arch.size = arch_hdr->size;
	arch.buf_index = 0;
	arch.file = macho->file;
	arch.opt = macho->opt;
	buf_in(&arch, macho->file, ft_strlen(macho->file));
	if (multi_arch) {
		buf_in(&arch, " (architecture ", 15);
		cpu = otool_cpu_type(arch_hdr->cputype);
		buf_in(&arch, cpu, ft_strlen(cpu));
		buf_in(&arch, ")", 1);
	}
	buf_in(&arch, ":\n", 2);
	return (otool_check_header(&arch));
}

int
otool_fat_header(struct macho_info *macho)
{
	struct fat_header *header;
	struct fat_arch *arch_hdr;
	ssize_t i;
	int ret;
	int err;

	if ((header = get_fat_header(macho)) == NULL)
		return (1);
	arch_hdr = macho->ptr + sizeof(struct fat_header);
	if ((i = get_arch(arch_hdr, header->nfat_arch, macho)) < 0)
		return (1);
	if (i == header->nfat_arch) {
		ret = 0;
		while (i--) {
			err = otool_fat_arch(arch_hdr++, macho,
				header->nfat_arch - 1);
			if (err < 0)
				return (-1);
			if (err)
				ret = 1;
		}
	} else {
		while (i--)
			arch_hdr++;
		ret = otool_fat_arch(arch_hdr, macho, 0);
	}
	return (ret > 0 ? 2 : ret);
}

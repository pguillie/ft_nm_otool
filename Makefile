# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:27:58 by pguillie          #+#    #+#              #
#    Updated: 2019/02/08 15:53:51 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM	= ft_nm
OTOOL	= ft_otool

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

LFT	= libft/libft.a

################################################################################
# LIBMACHO
################################################################################

LIB_INCDIR := libmacho/includes/
LIB_SRCDIR := libmacho/sources/

LIB_INCLUDES = \
$(addprefix $(LIB_INCDIR), \
	cpu_type.h \
	getters.h \
	libmacho.h \
)

LIB_SOURCES = \
$(addprefix $(LIB_SRCDIR), \
	buf_in.c \
	buf_out.c \
	get_arch_header.c \
	get_fat_arch.c \
	get_fat_header.c \
	get_load_command.c \
	get_mach_header_64.c \
	get_mach_header.c \
	get_nlist_64.c \
	get_nlist.c \
	get_section_64.c \
	get_section.c \
	get_segment_command_64.c \
	get_segment_command.c \
	get_symtab_command.c \
)

################################################################################
# NM
################################################################################

NM_INCDIR := nm/includes/
NM_SRCDIR := nm/sources/

NM_INCLUDES = $(LIB_INCLUDES) \
$(addprefix $(NM_INCDIR), \
	ft_nm.h \
	nm_error.h \
	nm_sort.h \
	symtree.h \
)

NM_SOURCES = $(LIB_SOURCES) \
$(addprefix $(NM_SRCDIR), \
	is_ascii_sorted_64.c \
	is_ascii_sorted.c \
	main.c \
	nm_arch_header.c \
	nm_check_header.c \
	nm_error.c \
	nm_fat_header.c \
	nm_mach_header_64.c \
	nm_mach_header.c \
	nm_map_file.c \
	nm_symtab_64.c \
	nm_symtab.c \
	nm_symbols_64.c \
	nm_symbols.c \
	symtree_add_64.c \
	symtree_add.c \
	symtree_create_64.c \
	symtree_create.c \
	symtree_delete_64.c \
	symtree_delete.c \
)

NM_OBJECTS = $(NM_SOURCES:%.c=%.o)

################################################################################
# OTOOL
################################################################################

OTOOL_INCDIR := otool/includes/
OTOOL_SRCDIR := otool/sources/

OTOOL_INCLUDES = $(LIB_INCLUDES) \
$(addprefix $(OTOOL_INCDIR), \
	ft_otool.h \
	otool_error.h \
)

OTOOL_SOURCES = $(LIB_SOURCES) \
$(addprefix $(OTOOL_SRCDIR), \
	main.c \
	otool_arch_header.c \
	otool_check_header.c \
	otool_error.c \
	otool_fat_header.c \
	otool_mach_header_64.c \
	otool_mach_header.c \
	otool_map_file.c \
	otool_text_64.c \
	otool_text.c \
)

OTOOL_OBJECTS = $(OTOOL_SOURCES:%.c=%.o)

################################################################################
# RULES
################################################################################

.PHONY: all nm otool clean fclean re

all: $(NM) $(OTOOL)

nm: $(NM)

otool: $(OTOOL)

$(NM): $(LFT) $(NM_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OTOOL): $(LFT) $(OTOOL_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

libmacho/%.o: libmacho/%.c Makefile $(LIB_INCLUDES)
	$(CC) $(CFLAGS) -I $(LIB_INCDIR) -c -o $@ $<

nm/%.o: nm/%.c Makefile $(NM_INCLUDES)
	$(CC) $(CFLAGS) -I $(NM_INCDIR) -I $(LIB_INCDIR) -c -o $@ $<

otool/%.o: otool/%.c Makefile $(OTOOL_INCLUDES)
	$(CC) $(CFLAGS) -I $(OTOOL_INCDIR) -I $(LIB_INCDIR) -c -o $@ $<

$(LFT):
	make -C $(dir $(LFT))

clean:
	make -C $(dir $(LFT)) clean
	rm -f $(NM_OBJECTS) $(OTOOL_OBJECTS)

fclean:
	make -C $(dir $(LFT)) fclean
	rm -f $(NM_OBJECTS) $(OTOOL_OBJECTS)
	rm -f $(NM) $(OTOOL)

re: fclean all

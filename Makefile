# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:27:58 by pguillie          #+#    #+#              #
#    Updated: 2019/01/17 18:36:31 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM		= ft_nm
OTOOL	= ft_otool

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

NMSOURCES = \
$(addprefix nm/sources/, \
	main.c \
	nm_file.c \
	nm_header.c \
	nm_mach_header.c \
) \
$(addprefix utils/sources/, \
	\
)

OTOOLSOURCES = $(addprefix otool/, \
)

NMOBJECTS = $(NMSOURCES:%.c=%.o)

OTOOLOBJECTS = $(OTOOLSOURCES:%c=%.o)

.PHONY: all nmclean nmfclean nmre otoolclean otoolfclean otoolre clean fclean re

all: $(NM) $(OTOOL)

$(NM): $(NMOBJECTS)
	echo $(NMOBJECTS)
	$(CC) -o $@ $^

nmclean:
	rm -f $(NMOBJECTS)

nmfclean: nmclean
	rm -f $(NM)

nmre: nmfclean nm

otoolclean:
	rm -f $(OTOOLOBJECTS)

otoolfclean: otoolclean
	rm -f $(OTOOL)

otoolre: otoolfclean otool

clean: nmclean otoolclean

fclean: nmfclean otoolfclean

re: fclean all

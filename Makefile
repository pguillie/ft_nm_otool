# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:27:58 by pguillie          #+#    #+#              #
#    Updated: 2019/01/16 19:39:23 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM		= ft_nm
OTOOL	= ft_otool

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

NMSOURCES = $(addprefix nm/, \
	main.c \
	nm_file.c \
	nm_header.c \
	nm_sym_32.c \
	nm_sym_64.c \
)

OTOOLSOURCES = $(addprefix otool/, \
)

NMOBJECTS = $(NMSOURCES:%.c=%.o)

OTOOLOBJECTS = $(OTOOLSOURCES:%c=%.o)

.PHONY: all nmclean nmfclean nmre otoolclean otoolfclean otoolre clean fclean re

all: $(NM) $(OTOOL)
	echo foo

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

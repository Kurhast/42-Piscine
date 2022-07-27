# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 12:05:58 by dapereir          #+#    #+#              #
#    Updated: 2022/07/27 12:10:03 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= main.c	utils-map-file.c	utils-map-file-2.c	utils-map.c		utils-map-2.c		utils-str.c

INCS	= ft_map.h

OBJS	= ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCS} Makefile
			${CC} ${CFLAGS} -I ${INCS} -o ${NAME} ${OBJS}

%.o:		%.c ${INCS} Makefile
			${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

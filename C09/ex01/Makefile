# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 16:28:17 by sdell-er          #+#    #+#              #
#    Updated: 2023/09/28 16:32:25 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCE	= srcs/
SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS	= ${addprefix ${SOURCE}, ${SRCS:.c=.o}}
HEAD	= includes
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
.c.o:
		${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
		ar -rc ${NAME} ${OBJS}
all :		${NAME}
clean:
		rm -f ${OBJS}
fclean:		clean
		rm -f ${NAME}
re:		fclean all
.PHONY:		all clean fclean re

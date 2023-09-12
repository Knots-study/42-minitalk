# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knottey <Twitter:@knottey>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 18:36:30 by knottey           #+#    #+#              #
#    Updated: 2023/09/12 18:37:09 by knottey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_FILES	= client.c minitalk_utils.c
CLIENT_OBJ		= ${CLIENT_FILES:.c=.o}

SERVER_FILES	= server.c minitalk_utils.c
SERVER_OBJ		= ${SERVER_FILES:.c=.o}

CC			= gcc -Wall -Wextra -Werror

AR			= ar rcs

INCLUDES	= -I. -I./libft/includes

LIB			= -L./libft/ -lft
LIBFT		= libft/libft.a

OPT_DEF		=

.c.o:
			${CC} -c ${INCLUDES} $< -o ${<:.c=.o} ${OPT_DEF}

all:		${LIBFT} client server

client:		${LIBFT} ${CLIENT_OBJ}
			${CC} ${INCLUDES} -o client ${CLIENT_OBJ} ${OPT_DEF} ${LIB}

server:		${LIBFT} ${SERVER_OBJ}
			${CC} ${INCLUDES} -o server ${SERVER_OBJ} ${OPT_DEF} ${LIB}

${LIBFT}:
			$(MAKE) -C ./libft ft_printf

clean:
			rm -f ${CLIENT_OBJ} ${SERVER_OBJ}
			make -C ./libft clean

fclean:		clean
			make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re

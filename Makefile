# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knottey <Twitter:@knottey>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 18:36:30 by knottey           #+#    #+#              #
#    Updated: 2023/09/14 09:45:26 by knottey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = 42-libft/libft.a

CC = cc
CCFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CC} ${CCFLAGS} ${OBJS_SERVER} 42-libft/libft.a -o ${SERVER}
		${CC} ${CCFLAGS} ${OBJS_CLIENT} 42-libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./42-libft

clean:	
		$(MAKE) clean -C ./42-libft
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
		$(MAKE) fclean -C ./42-libft
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:		all clean fclean re

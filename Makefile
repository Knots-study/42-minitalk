# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knottey <Twitter:@knottey>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 18:36:30 by knottey           #+#    #+#              #
#    Updated: 2023/09/16 12:23:24 by knottey          ###   ########.fr        #
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
INCLUDES = -I ./42-Libft -I ./42-Libft/42-ft_printf/include

all: $(SERVER) $(CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CC} ${CCFLAGS} ${OBJS_SERVER} $(LIBFT)  ./42-libft/42-ft_printf/libftprintf.a -o ${SERVER} $(INCLUDES)
		${CC} ${CCFLAGS} ${OBJS_CLIENT} $(LIBFT)  ./42-libft/42-ft_printf/libftprintf.a -o ${CLIENT} $(INCLUDES)

$(LIBFT):
		${MAKE} -C ./42-libft
		${MAKE} -C ./42-libft/42-ft_printf

clean:	
		$(MAKE) clean -C ./42-libft
		${MAKE} clean -C ./42-libft/42-ft_printf
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
		$(MAKE) fclean -C ./42-libft
		${MAKE} fclean -C ./42-libft/42-ft_printf
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:		all clean fclean re

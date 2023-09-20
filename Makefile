# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 11:58:31 by hcherpre          #+#    #+#              #
#    Updated: 2022/02/08 18:19:43 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     =   so_long

CC       =   gcc

RM       =   rm -rf

CFLAGS   =   -Wall -Wextra -Werror

SRCS     =   so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
			tab.c map.c move.c move2.c check.c free.c

OBJS     =   ${SRCS:.c=.o}

LIBFT    =   ./libft/libft.a

all:   lib ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

.c.o: $(LIBFT)
	$(CC) $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}
	
lib:
			make -C libft
clean:
	${RM} ${OBJS}
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	${RM} $(LIBFT)

re:    fclean all

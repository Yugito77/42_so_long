# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 10:03:37 by hcherpre          #+#    #+#              #
#    Updated: 2021/12/02 10:04:56 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = libft.a

CC     = gcc

LINKER     = ar rcs

RM     = rm -rf

SRCS     = ft_isalpha.c ft_isdigit.c ft_isalnum.c\
    ft_isascii.c ft_isprint.c ft_strlen.c\
    ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
    ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
    ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
    ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS		= ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c

OBJS        = ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CFLAGS     = -Wall -Wextra -Werror

$(NAME): ${OBJS}
	${LINKER} ${NAME} ${OBJS}

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${OBJS} ${OBJS_BONUS}
		${LINKER} ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re:    fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 13:49:07 by nibenoit          #+#    #+#              #
#    Updated: 2023/06/15 17:38:10 by nibenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g

### EXECUTABLE ###
NAME		= philo
ARGS		= 0

### INCLUDES ###
SRCS_DIR	= src
INC_DIR		= incl

### SOURCE FILES ###
SRCS_FILES	=	main.c \
				parse.c \
				utils.c \
				error.c \
				philo_utils.c \
				thread.c \
				philo_routine.c \
				time.c

### HEADER FILES ###
HEADER_FILE	= philo.h
HEADER		= $(addprefix ${INC_DIR}/, ${HEADER_FILE})

### OBJECTS ###
SRCS		= $(addprefix ${SRCS_DIR}/, ${SRCS_FILES})
OBJS		= ${SRCS:.c=.o}

### COLORS ###
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

### OTHERS ###
RM			= rm -f

### RULES ###
%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I${INC_DIR} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@echo "$(NAME): $(RED)Supressing object files$(RESET)"
	@rm -rf $(OBJS)

fclean:	clean
	@echo "$(NAME): $(RED)Supressing program file$(RESET)"
	@rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re bonus

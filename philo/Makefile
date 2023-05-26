NAME		= philo

SRCS_FILES	= main.c

HEADER_FILE	= philo.h

SRCS_DIR	= ./srcs/
INC_DIR		= ./includes/

LIBFT		= ./libft/libft.a
LIBFT_PATH	= ./libft

SRCS		= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS		= ${SRCS:.c=.o}
HEADER		= $(addprefix ${INC_DIR}, ${HEADER_FILE})

CC			= cc
CC_FLAGS	= -Wall -Wextra -Werror -g

RM			= rm -f

%.o : %.c	${HEADER}
			${CC} ${CC_FLAGS} -I${INC_DIR} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CC_FLAGS} -I${INC_DIR} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
			make -C clean
			${RM} ${OBJS} ${BONUS_OBJS}
			@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:		clean
			make -C fclean
			${RM} ${NAME} ${NAME_BONUS}
			@echo "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY: 	all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

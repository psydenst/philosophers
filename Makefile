SRCS = src/main.c \
	   src/routines.c \
	   src/verification.c \
	   src/populate_phil.c \
	   src/forks.c \
	   src/mutex.c \
	   src/utils.c

NAME = philo

OBJS = ${SRCS:.c=.o}

CC = cc

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf 

HEADER = inc/philo.h

all: $(NAME)

$(NAME): $(OBJS)
	${CC} -g -I ${HEADER} ${CFLAGS} ${OBJS} -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	${RM} ${NAME}

re: fclean all

run: all
	clear
	./${NAME} 5 800 200 200

.PHONY: all clean fclean re bonus

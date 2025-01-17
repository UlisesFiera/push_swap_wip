NAME 					= push_swap

LIBFT					= ./src/libft/libft.a

CC						= gcc

STD_FLAGS				= -Wall -Wextra -Werror

SRCS					= src/main.c \
						  src/dup_int.c \
						  src/populate_stack_one.c

OBJS					= ${SRCS:.c=.o}

REMOVE					= rm -f ${OBJS}; rm -f push_swap; rm -f *.out

all:					${LIBFT} ${NAME}

${NAME}:
						${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} -o ${NAME}

${LIBFT}:				
						make bonus -C ./src/libft

clean:
						${REMOVE}

fclean:					clean
						make fclean -C ./src/libft
						
re:						clean all

.PHONY:					all clean fclean re
NAME 					= push_swap

LIBFT					= ./src/libft/libft.a

CC						= gcc

STD_FLAGS				= -Wall -Wextra -Werror

SRCS					= src/main.c \
						  src/append_node.c \
						  src/error_check.c \
						  src/free_stack.c \
						  src/ft_atol.c \
						  src/populate_a.c \
						  src/is_sorted.c \
						  src/set_index.c \
						  src/sort_three.c \
						  src/stack_a_setup.c \
						  src/stack_b_setup.c \
						  src/stack_utils.c \
						  src/talgo.c \
						  src/operations/push.c \
						  src/operations/reverse_rotate.c \
						  src/operations/rotate.c \
						  src/operations/swap.c \

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
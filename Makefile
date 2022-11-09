NAME			=	push_swap

PRINTF_PATH		=	./my_libs/ft_printf/
LIBFT_PATH 		=	./my_libs/ft_libft/
HEADER			=	-I ./includes

PRINTF 			=	$(PRINTF_PATH)libftprintf.a
LIBFT 			=	$(LIBFT_PATH)libft.a

SRC_FILES 		=	push_swap.c  initialize_variables.c error_checking.c \
					 sorting_algorithms.c utils_node.c \
					stack_many_operations.c stack_single_operations.c \
					checking_algorithms.c simplify_number.c utils.c

SRC_PATH		=	./srcs
OBJ_PATH		=	./obj

SRC 			=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ 			=	$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror

RM				=	rm -rf

all:	$(NAME)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(HEADER) $(OBJ) $(PRINTF) $(LIBFT) $(CFLAGS) -o $@ 

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC)  -c  $(CFLAGS)  $< -o $@ $(HEADER)

.c.o:
		$(CC)  -c  $(CFLAGS)  $< -o $@

$(PRINTF):
			make -C $(PRINTF_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)
			make bonus -C $(LIBFT_PATH)

val:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG)

clean:
			${RM} ${OBJ_PATH}
			cd $(PRINTF_PATH) && make clean 
			cd $(LIBFT_PATH) && make clean 

fclean:		clean
			${RM} ${NAME}
			${RM} ${PRINTF}
			${RM} ${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re
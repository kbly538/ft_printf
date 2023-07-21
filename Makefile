NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf ft_printchar ft_printint ft_printstring \
					ft_printhex ft_printpointer ft_printuint ft_utils \
					ft_flags ft_ldtoa ft_xtoa ft_ptoa
SRCS 			=	$(addsuffix .c, $(SRC))

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					@$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				@cp	$(LIBFT) $(NAME)
					@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					@$(MAKE) -C $(LIBFT_PATH) all

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					@$(MAKE) -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME)

re:					fclean all

strict-test:				all
					gcc $(CFLAGS) tests.c $(NAME)
					@echo "=============== Starting strict tests ================"
					@./a.out | cat -e
					@echo "===============  Ending tests ================"


test:				all
					gcc tests.c $(NAME)
					@echo "=============== Starting stricttests ================"
					@./a.out | cat -e
					@echo "===============  Ending tests ================"

leak:				all
					@gcc $(CFLAGS) tests.c $(NAME) 
					@valgrind --leak-check=full ./a.out

debugit:			all
					@gcc $(CFLAGS) tests.c $(NAME)
					gdb ./a.out

.PHONY:				all bonus clean fclean re libft test
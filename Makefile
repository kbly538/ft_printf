NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

AR				=	ar
ARFLAGS 		=	rcs

RM				=	rm -rf

LIBFT			=	../libft.a

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
SRC				=	ft_printf ft_printf_utils\
					ft_print_char \
					ft_print_string \
					ft_print_pointer \
					ft_print_percent \
					ft_print_int ft_int_format_utils ft_print_int_utils \
					ft_print_uint ft_uint_format_utils ft_print_uint_utils \
					ft_print_hex ft_hex_format_utils ft_print_hex_utils \
					ft_flag_utils ft_flags ft_ldtoa ft_xtoa ft_ptoa ft_generic_utils \

SRCS 			=	$(addsuffix .c, $(SRC))

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
					@cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					$(MAKE) -C $(LIBFT) all

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					
all:				$(NAME)

bonus:				all

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)
re:					fclean all

.PHONY:				all bonus clean fclean re libft test
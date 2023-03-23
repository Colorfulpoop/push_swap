SRC = push_swap.c start.c sort.c ./operations/swap.c ./operations/push.c ./operations/rotate.c \
		./operations/reverse_rotate.c quick_sort_utils.c  quick_sort.c push_swap_utils.c \
		./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c checker_utils.c
SRC_B = start.c sort.c ./operations/swap.c ./operations/push.c ./operations/rotate.c \
		./operations/reverse_rotate.c quick_sort_utils.c  quick_sort.c push_swap_utils.c \
		./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c checker_utils.c
OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
NAME = push_swap

CC = gcc -Wall -Wextra -Werror
FT_PRINTF = lib/ft_printf
LIBFT = lib/libft
LIBRARY = lib/ft_printf/libftprintf.a lib/libft/libft.a

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

all	: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@$(CC) $(OBJ) $(LIBRARY) -o $(NAME)
	@mv lib/ft_printf/libftprintf.a bonus
	@mv lib/libft/libft.a bonus
	ar rcs push_swap.a $(OBJ_B)
	@mv push_swap.a bonus


clean :
	@make clean -C $(FT_PRINTF)
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C $(FT_PRINTF)
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

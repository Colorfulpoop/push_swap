SRC = push_swap.c start.c sort.c ./operations/swap.c ./operations/push.c ./operations/rotate.c \
		./operations/reverse_rotate.c quick_sort_utils.c  quick_sort.c push_swap_utils.c ./bonus/checker.c
OBJ = ${SRC:.c=.o}
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

NAME		= ft_ls
LIB			= lslib.a
FILENAMES	= main.c setup.c extra.c sort.c tabs.c print.c
HEADER		= .
FLAGS		= -Wall -Wextra -Werror

SRC			= $($(FILENAMES))
OBJ			= $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re test

all : $(NAME)

$(NAME) : $(LIB)
	gcc $(FLAGS) -I. -I libft libft/libft.a $(LIB) -o $(NAME)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	make -C libft

build/%.o: %.c | build
	gcc $(FLAGS) -I $(HEADER) -I libft -I. -c $^ -o $@

build:
	mkdir build

clean:
	rm -rf build
	rm -f $(LIB)
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

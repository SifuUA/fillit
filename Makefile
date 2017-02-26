NAME = fillit
SRC = main.c ft_arr_putstr.c get_figure_from_string.c creating_typed_array.c test_size.c test_size_helpers.c check.c ft_get_s_from_stream_or_file.c ft_strlen.c ft_putendl.c ft_putstr.c ft_strsplit.c ft_memcpy.c ft_strnew.c ft_memalloc.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror 
OFLAGS = -o $(NAME)
CC = gcc 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(OFLAGS)
.c.o:
	$(CC) $(CFLAGS) $<
clean:
	rm -f $(OBJ)
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all

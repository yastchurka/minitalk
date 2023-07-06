CC = cc -Wall -Wextra -Werror

all: server client

server: server.o
		make -C ft_printf
		$(CC) server.o ft_printf/libftprintf.a -o server

client: client.o
		make -C ft_printf
		$(CC) client.o ft_printf/libftprintf.a -o client

clean:
		make clean -C ft_printf 
		rm -f server.o client.o

fclean: clean
		make fclean -C ft_printf 
		rm -f server client

re: fclean all

.PHONY: all clean fclean re

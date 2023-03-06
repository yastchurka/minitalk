@CC = cc -Wall -Wextra -Werror

all: comp_start server client

#........COLORS
COLOR	=	\033[1;36m

NO_COLOR	=	\033[0m


#........MESSAGES
COMP_START	=	echo "\n $(COLOR)Make: Starting the compilation...$(NO_COLOR)\n"

SERV_READY	=	echo "\n $(COLOR)-------- Server compiled! -------- $(NO_COLOR)\n"

CLI_READY	=	echo "\n $(COLOR)-------- Client compiled! -------- $(NO_COLOR)\n"

CLEANED		=	echo "\n $(COLOR)-------- Clean: Removed all the \".o\" files -------- $(NO_COLOR)\n"

FCLEANED	=	echo "\n $(COLOR)-------- Fclean: Removed the executables -------- $(NO_COLOR)\n"


#........RULES
comp_start:
	@$(COMP_START)

server: server.o
		@$(CC) server.o -o server
		@$(SERV_READY)

client: client.o
		@$(CC) client.o -o client
		@$(CLI_READY)

clean:
		@rm -f server.o client.o
		@$(CLEANED)

fclean: clean
		@rm -f server client
		@$(FCLEANED)

re: fclean all

#make -C ft_printf
#make -C ft_printf
#make clean -C ft_printf 
#make fclean -C ft_printf

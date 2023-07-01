CC = cc
CFLAGS = -Wall -Wextra -Werror

# List of source files
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

# List of object files to build
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Build both the client and server executables
all: $(NAME) client server

# Build the client executable
client: $(CLIENT_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $@

# Build the server executable
server: $(SERVER_OBJS) $(NAME) 
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) client server 

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re

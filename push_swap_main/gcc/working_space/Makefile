NAME = a.out
CL = clang
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
STEP = -g 00
SANI = -fsanitize=address
LEAK = -fsanitize=leak
SRCS = push_swap_main.c push_swap_first.c stack.c 
OBJS = $(SRCS:.c=.o)
	GIT = git

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

step:  $(OBJS)
	$(CC) $(CFLAGS) $(STEP) -o $(NAME) $(OBJS)

sani:  $(OBJS)
	$(CC) $(CFLAGS) $(SANI) -o $(NAME) $(OBJS)

leak: $(OBJS)
	$(CL) $(CFLAGS) $(LEAK) -o $(NAME) $(OBJS)


.PHONY: clean fclean re

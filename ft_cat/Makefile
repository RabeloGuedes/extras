CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

NAME = ft_cat

all: $(NAME)

$(NAME): $(NAME).c
	$(CC) $(CFLAGS) $(INCLUDES) $(NAME).c -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

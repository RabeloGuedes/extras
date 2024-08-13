CC = cc
CFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I./includes

NAME = ft_head

all: $(NAME)

$(NAME): $(NAME).c
	$(CC) $(CFLAGS) $(INCFLAGS) $< -o $@

clean:
	rm -rf $(NAME)

re: clean all

SRCS = error.c infos.c main.c run.c utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = philo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
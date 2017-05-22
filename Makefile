##
## Makefile for Makefile in /home/Vatoth/PSU_2016_navy
##
## Made by Quentin Sonnefraud
## Login   <Vatoth@epitech.net>
##
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Mon May 22 23:31:05 2017 
##

NAME    = navy

SRC     = src/function.c \
	  src/function2.c \
	  src/function3.c \
	  src/player1.c \
	  src/main.c \
	  src/norme.c \
	  src/check.c \
	  src/player2.c \
          src/game.c \
	  src/my_str_to_wordtab.c \
	  src/stream.c \
	  src/get_next_line.c \
	  my_printf/my_putchar.c \
	  my_printf/my_strlen.c \
          my_printf/my_printable.c \
          my_printf/my_putstr.c \
          my_printf/my_put_nbr.c \
          my_printf/my_put_long.c \
          my_printf/my_printf.c \
          my_printf/my_base.c \
          my_printf/my_put_pointers.c \
          my_printf/my_put_unsigned.c \
          my_printf/my_revstr.c

OBJS    = $(SRC:.c=.o)

CC	= gcc

CPPFLAGS += -I./include

CFLAGS	+= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

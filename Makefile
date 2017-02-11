##
## Makefile for Makefile in /home/Vatoth/PSU_2016_navy
##
## Made by Quentin Sonnefraud
## Login   <Vatoth@epitech.net>
##
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Fri Feb 10 11:02:34 2017 Quentin Sonnefraud
##

NAME    = navy

SRC     = function.c \
	  function2.c \
	  function3.c \
	  player1.c \
	  check.c \
	  player2.c \
          game.c \
	  my_str_to_wordtab.c \
	  stream.c \
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

all:    $(OBJS)
	gcc $(OBJS) -o $(NAME)  -g3 -Wall -Wextra -Werror -pedantic libgnl.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

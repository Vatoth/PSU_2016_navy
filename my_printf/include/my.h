/*
** my.h for my.h in /home/Vatoth/PSU_2016_my_printf/include
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Wed Nov  9 10:40:56 2016 Quentin Sonnefraud
** Last update Fri Feb 10 10:13:08 2017 Vatoth
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	my_put_nbr(int	nb);
int	my_printf(char *flag, ...);
void	my_putchar(char	c);
int	my_putstr(char	*str);
long	my_put_binary(int	nbr);
void	my_put_long(long	nb);
int	my_flag(char	*flag, int	i, va_list	ap);
int	my_base(int	nb, char	*str);
int	my_printable(char	*str);
int	my_strlen(char	*str);
char	*my_revstr(char	*str);
int	my_put_pointers(long	str);
long	my_base_pointers(long	nbr, char *base);
int	my_put_unsigned(unsigned int	nbr);

#endif /* !MY_H_ */

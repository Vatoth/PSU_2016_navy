/*
** my_printf.c for my_printf.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Tue Nov  8 15:26:20 2016 Quentin Sonnefraud
** Last update Fri Feb 10 10:12:27 2017 Vatoth
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int		my_printf(char *flag, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, flag);
  if (flag == NULL)
    return (0);
  else
    while (flag[i] != '\0')
      {
	while (flag[i] == '%')
	  {
	    i = i + 1;
	    my_flag(flag, i, ap);
	    i = i + 1;
	  }
	if (flag[i] == '\0')
	  return (0);
	else if (flag[i] != '%')
	  my_putchar(flag[i]);
	i = i + 1;
      }
  return (0);
}

int	my_flag(char *flag, int i, va_list ap)
{
  if (flag[i] == 'd' || flag[i] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (flag[i] == 'l')
    my_put_long(va_arg(ap, long));
  else if (flag[i] == 'c')
    my_putchar(va_arg(ap, int));
  else if (flag[i] == 's')
    my_putstr(va_arg(ap, char *));
  else if (flag[i] == 'b')
    my_base(va_arg(ap, int), "01");
  else if (flag[i] == 'o')
    my_base(va_arg(ap, int), "01234567");
  else if (flag[i] == 'x')
    my_base(va_arg(ap, int), "0123456789abcdef");
  else if (flag[i] == 'S')
    my_printable(va_arg(ap, char *));
  else if (flag[i] == '%')
    my_putchar('%');
  else if (flag[i] == 'p')
    my_put_pointers(va_arg(ap, long));
  else if (flag[i] == 'u')
    my_put_unsigned(va_arg(ap ,unsigned int));
  return (0);
}

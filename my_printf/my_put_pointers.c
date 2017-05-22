/*
** my_put_pointers.c for my_put_pointers in /home/Vatoth/PSU_2016_my_printf
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Nov 15 15:06:23 2016 Quentin Sonnefraud
** Last update Mon Feb 20 12:40:57 2017 Vatoth
*/

#include "include/my.h"

int	my_put_pointers(long ptr)
{
  my_putstr("0x");
  my_base_pointers(ptr, "0123456789abdcef");
  return (0);
}

long	my_base_pointers(long nb, char *base)
{
  long	result;
  long	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  result = nb / my_strlen(base);
  modulo = nb % my_strlen(base);
  if (result > 0)
    my_base_pointers(result, base);
  my_putchar(base[modulo]);
  return (0);
}

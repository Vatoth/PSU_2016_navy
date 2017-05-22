/*
** my_base.c for my_base.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Tue Nov 15 12:08:39 2016 Quentin Sonnefraud
** Last update Sun Feb 19 10:40:24 2017 Vatoth
*/

#include "include/my.h"

int	my_base(int nb, char *base)
{
  int	result;
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  result = nb / my_strlen(base);
  modulo = nb % my_strlen(base);
  if (result > 0)
    my_base(result, base);
  my_putchar(base[modulo]);
  return (0);
}

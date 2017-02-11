/*
** my_put_nbr.c for my_put_nbr.c in /home/Vatoth/CPool_Day05
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Mon Oct 11 10:58:54 2016 Quentin Sonnefraud
** Last update Wed Nov  9 10:51:55 2016 Quentin Sonnefraud
*/

#include "include/my.h"

int	my_put_nbr(int nb)
{
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 0)
    {
      if ( nb > 9)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(nb + 48);
	}
    }
}

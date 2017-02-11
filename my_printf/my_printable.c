/*
** my_printable.c for my_printable.c in /home/Vatoth/PSU_2016_my_printf
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Nov 10 15:20:13 2016 Quentin Sonnefraud
** Last update Fri Feb 10 10:06:56 2017 Vatoth
*/

#include "include/my.h"

int	my_printable(char *str)
{
  int  c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 7)
	{
	  my_putstr("\\00");
	  my_base(str[c++], "01234567");
	}
      else if (str[c] > 7 && str[c] < 32)
	{
	  my_putstr("\\0");
	  my_base(str[c++], "01234567");
	}
      else if (str[c] >= 127)
	{
	  my_putstr("\\");
	  my_base(str[c++], "01234567");
	}
      else
	my_putchar(str[c++]);
    }
  return (0);
}

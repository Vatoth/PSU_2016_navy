/*
** my_putstr.c for my_putstr in /home/Vatoth/CPool_Day04
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Oct  6 16:03:08 2016 Quentin Sonnefraud
** Last update Wed Nov  9 10:51:32 2016 Quentin Sonnefraud
*/

#include "include/my.h"

int	my_putstr(char *str)
{
  char	c;

  c = 0;
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c = c + 1;
    }
  return (0);
}

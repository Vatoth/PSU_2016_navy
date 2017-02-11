/*
** my_revstr.c for my_revstr in /home/Vatoth/CPool_Day06
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Mon Oct 10 15:51:14 2016 Quentin Sonnefraud
** Last update Tue Nov 15 14:35:19 2016 Quentin Sonnefraud
*/

#include "include/my.h"

char    *my_revstr(char *str)
{
  int   memory;
  int   a;
  int   b;
  int   c;

  a = 0;
  b = my_strlen(str) - 1;
  c = (my_strlen(str) - 1) / 2;
  while (a <= c)
    {
      memory = str[a];
      str[a] = str[b];
      str[b] = memory;
      a = a + 1;
      b = b - 1;
    }
  return (str);
}

/*
** function2.c for function2.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Feb  1 10:38:54 2017 Quentin Sonnefraud
** Last update Fri Feb 10 11:03:05 2017 Quentin Sonnefraud
*/

#include "navy.h"

int     my_atoi(char *str)
{
  int   res;
  int   i;

  i = 0;
  res = 0;
  while (str[i])
    res = res * 10 + str[i++] - '0';
  return res;
}

void	freeTable(char **tableau)
{
  free(tableau[0]);
  free(tableau);
}

void	my_evil_str(char *str)
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
      str[a++] = str[b];
      str[b--] = memory;
    }
}

/*
** function3.c for function3.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Feb  1 22:19:37 2017 Quentin Sonnefraud
** Last update Mon Feb 20 12:47:31 2017 Vatoth
*/

#include "navy.h"

void	freeTable2(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void	my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        {
          if (((str[i - 1] >= '0') && (str[i - 1] <= '9'))
	      || ((str[i - 1] >= 'A') && (str[i - 1] <= 'Z'))
	      || ((str[i - 1] >= 'a') && (str[i - 1] <= 'z')))
            str[i] = str[i] + 32;
        }
      else if (str[i] >= 'a' && str[i] <= 'z')
        {
          if (((str[i - 1] >= ' ') && (str[i - 1] < '0'))
	      || ((str[i - 1] > '9') && (str[i - 1] < 'A'))
	      || ((str[i - 1] > 'Z') && (str[i - 1] < 'a'))
	      || (str[i - 1] < 'z'))
            str[i] = str[i] - 32;
            }
      i++;
    }
}

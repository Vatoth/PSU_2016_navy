/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Vatoth/PSU_2016_minishel
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Jan 18 11:38:15 2017 Quentin Sonnefraud
** Last update Fri Feb 10 12:17:28 2017 Quentin Sonnefraud
*/

#include "navy.h"

int	count_words(char *str, char separator)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      while (str[i] && str[i] != separator && str[i] != '\t')
	i++;
      nb++;
      while (str[i] && (str[i] == separator || str[i] == '\t'))
	i++;
    }
  nb++;
  return (nb);
}

char    **my_str_to_wordtab(char *str, char s)
{
  t_tab	tab;

  tab.i = 0;
  tab.y = 0;
  tab.k = 0;
  if ((tab.array = malloc(sizeof(*tab.array) * count_words(str, s))) == NULL)
    return (NULL);
  tab.nb = 0;
  while (str[tab.i] != '\0')
    {
      tab.nb = tab.i;
      while (str[tab.nb] && str[tab.nb] != s && str[tab.nb] != '\t')
	tab.nb++;
      if ((tab.array[tab.k] = malloc(sizeof(tab.array) * tab.nb)) == NULL)
	return (NULL);
      tab.nb = 0;
      tab.y = 0;
      while (str[tab.i] && str[tab.i] != s && str[tab.i] != '\t')
	tab.array[tab.k][tab.y++] = str[tab.i++];
      tab.array[tab.k++][tab.y] = '\0';
      while (str[tab.i] && (str[tab.i] == s || str[tab.i] == '\t'))
	tab.i++;
    }
  tab.array[tab.k] = NULL;
  return (tab.array);
}

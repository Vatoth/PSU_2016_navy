/*
** check.c for check.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Mon Feb  6 05:26:22 2017 Quentin Sonnefraud
** Last update Fri Feb 10 21:45:19 2017 Quentin Sonnefraud
*/

#include "navy.h"

char	*check(void)
{
  char	*s;

  my_putstr("\nattack: \e[3m");
  if ((s = get_next_line(0)) == NULL)
    {
      my_printf("\e[0m\nwrong positions");
      return (check());
    }
  my_putstr("\e[0m");
  if (my_strlen(s) > 2)
    {
      my_putstr("wrong positions");
      free(s);
      return (check());
    }
  if (s[0] >= '1' && s[0] <= '8')
    my_evil_str(s);
  if (s[0] >= 'a' && s[0] <= 'h')
    my_strcapitalize(s);
  if (s[0] < 'A' || s[0] > 'H' || s[1] < '1' || s[1] > '8')
    {
      my_putstr("wrong positions");
      free(s);
      return (check());
    }
  return (s);
}

int	win(char **str)
{
  int	i;
  int	j;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i][j])
	{
	  if (str[i][j] == 'x')
	    nb++;
	  j++;
	}
      i++;
    }
  if (nb == 14)
    return (1);
  return (0);
}

int     check_pos2(char **pos, int i)
{
  if (pos[i][0] < '2' && pos[i][0] > '5')
    return (-1);
  if ((pos[i][2] < 'A' && pos[i][2] > 'H') ||
      (pos[i][2] < '1' && pos[i][2] > '8'))
    return (-1);
  if ((pos[i][3] < 'A' && pos[i][3] > 'H') ||
      (pos[i][3] < '1' && pos[i][3] > '8'))
    return (-1);
  if ((pos[i][5] < 'A' && pos[i][5] > 'H') ||
      (pos[i][5] < '1' && pos[i][5] > '8'))
    return (-1);
  if ((pos[i][6] < 'A' && pos[i][6] > 'H') ||
      (pos[i][6] < '1' && pos[i][6] > '8'))
    return (-1);
}

int	check_pos(char **pos)
{
  int	len;
  int	i;

  i = 0;
  len = 0;
  while (pos[i])
    {
      my_strcapitalize(pos[i]);
      if (check_pos2(pos, i) == -1)
	{
	  my_puterror("bad boat\n");
	  return (-1);
	}
      len = pos[i++][0] - '0' + len;
    }
  if (len != 14)
    {
      my_puterror("bad boat\n");
      return (-1);
    }
  if (i != 4)
    {
      my_puterror("bad boat\n");
      return (-1);
    }
  return (0);
}

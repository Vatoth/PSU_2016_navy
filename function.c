/*
** function.c for function.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Jan 31 14:20:24 2017 Quentin Sonnefraud
** Last update Fri Feb 10 22:53:24 2017 Quentin Sonnefraud
*/

#include "navy.h"

int	print_h(void)
{
  my_printf("USAGE\n           ./navy [first_player_pid] navy_positions\n");
  my_printf("DESCRIPTION\n           first_player_pid only for the 2nd player. pid of the first player.\n");
  my_printf("            navy_positionsfile representing the positions of the ships\n");
}

void	my_puterror(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(2, str, i);
}

void	*my_memset(void	*str, int c, size_t n)
{
  char	*d;

  d = str;
  while (n > 0)
    {
      *d++ = c;
      n = n - 1;
    }
  return (str);
}

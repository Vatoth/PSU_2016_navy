/*
** main.c for navy in /home/Vatoth/Epitech/PSU_2016_navy
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Feb 18 13:26:39 2017 Quentin Sonnefraud
** Last update Sun Feb 19 10:33:29 2017 Vatoth
*/

#include "navy.h"

char    **cat_balls(t_pos pos, int len, char **str, char **map)
{
  if (pos.y == pos.y1)
    {
      while (len > 0)
	{
	  if (pos.x > 14)
	    return (NULL);
	  if (map[pos.y][pos.x] != '.')
	    return (NULL);
	  map[pos.y][pos.x] = str[0][0];
	  if (pos.x < pos.x1)
	    pos.x = pos.x + 2;
	  else
	    pos.x = pos.x - 2;
	  len--;
	}
      return (map);
    }
  return (NULL);
}

int     check_lol(char *s)
{
  int   i;
  int	count;

  i = 0;
  count = 0;
  while (s[i])
    {
      if (s[i] == ':')
	count = count + 1;
      i++;
    }
  if (count != 2)
    return (-1);
  return (0);
}

int     main(int argc, char **argv)
{
  int   check;

  if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    print_h();
  else if (argc == 2)
    {
      check = player_one(argv[1]);
      if (check == 0)
        my_printf("I won\n");
      else if (check == 1)
        my_printf("Enemy won\n");
      else
        check = 84;
    }
  else if (argc == 3)
    {
     check = player_two(my_atoi(argv[1]), argv[2]);
      if (check == 0)
        my_printf("I won\n");
      else if (check == 1)
        my_printf("Enemy won\n");
      else
        check = 84;
    }
  return (check);
}

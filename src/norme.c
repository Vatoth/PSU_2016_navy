/*
** norme.c for navy in /home/Vatoth/Epitech/PSU_2016_navy
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Feb 18 13:18:12 2017 Quentin Sonnefraud
** Last update Mon Feb 20 11:53:23 2017 Vatoth
*/

#include "navy.h"

extern int	g_global;

int     dog_one(int pid, char **map, char **enemy_map)
{
  int   x;
  int   y;

  my_putstr("\nwaiting for enemy's attack...\n");
  g_global = 0;
  while (g_global == 0)
    pause();
  x = g_global;
  pause();
  while (g_global == 0)
    pause();
  y = g_global;
  my_printf("%c%c", x + 'A' - 1, y + '1' - 1);
  check_hit(map, x, y, pid);
  map = set_x(map, x, y);
  if (win(map) == 1)
    return (1);
  printmap(map, enemy_map, 1);
  return (0);
}

int     follow_traduction(int y, int pid)
{
  if (put_sig(pid, 1))
    return (-1);
  while (y >= 0)
    {
      usleep(1000);
      if (put_sig(pid, 0) == -1)
        return (-1);
      y--;
    }
  usleep(1000);
  if (put_sig(pid, 1) == -1)
    return (-1);
  return (0);
}

int     meow(int len, int i)
{
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

char	**dudu(t_pos pos, int len, char **str, char **map)
{
  if (pos.x == pos.x1)
    {
      while (len > 0)
        {
          if (pos.y > 7)
	    return (NULL);
	  if (map[pos.y][pos.x] != '.')
	    return (NULL);
          map[pos.y][pos.x] = str[0][0];
	  if (pos.y < pos.y1)
	    pos.y++;
	  else
	    pos.y--;
	  len--;
        }
      return (map);
    }
  if (cat_balls(pos, len, str, map) == NULL)
    return (NULL);
  else
    return (map);
  return (NULL);
}

void    dog_two(char **map, int pid)
{
  int   x;
  int   y;

  my_putstr("\nwaiting for enemy's attack...\n");
  g_global = 0;
  while (g_global == 0)
    pause();
  x = g_global;
  pause();
  while (g_global == 0)
    pause();
  y = g_global;
  my_putchar(x + 'A' - 1);
  my_putchar(y + '1' - 1);
  check_hit(map, x, y, pid);
  map = set_x(map, x, y);
}

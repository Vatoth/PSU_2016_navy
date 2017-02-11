/*
** player2.c for player2.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Thu Feb  2 10:53:14 2017 Quentin Sonnefraud
** Last update Fri Feb 10 21:31:15 2017 Quentin Sonnefraud
*/

#include "time.h"
#include "navy.h"

extern	int g_global;

int     player_two(int  pid, char *path)
{
  char  **map;
  char  **pos;
  char  **enemy_map;
  int   i;
  char  *s;

  if ((enemy_map = allocation("map", 9, 17)) == NULL)
    return (-1);
  if ((map = allocation("map", 9, 17)) == NULL)
    return (-1);
  if ((pos = allocation(path, 5, 9)) == NULL)
    return (-1);
  if (check_pos(pos) == -1)
    return (-1);
  i = 0;
  while (pos[i] != NULL)
    if ((map = analyse(my_str_to_wordtab(pos[i++], ':'), map)) == NULL)
      return (-1);
  if (put_sig(pid, 1) == -1)
    return (-1);
  get_sig();
  pause();
  g_global = 0;
  my_putstr("successfully connected\n");
  my_putstr("my_pid: ");
  freeTable(pos);
  printmap(map, enemy_map, 0);
  i = follow(pid, map, enemy_map);
  return (i);
}

int	check_hit(char **map, int x, int y, int pid)
{
  if (map[y - 1][(x - 1) * 2] == '.' || map[y - 1][(x - 1) * 2] == 'o')
    {
      my_putstr(": missed\n");
      put_sig(pid, 0);
      usleep(1000);
      put_sig(pid, 1);
      return (1);
    }
  else if (map[y - 1][(x - 1) * 2] != '.' || map[y - 1][(x - 1) * 2] == 'x')
    {
      my_putstr(": hit\n");
      put_sig(pid, 0);
      usleep(1000);
      put_sig(pid, 0);
      usleep(1000);
      put_sig(pid, 1);
      return (2);
    }
}

char	**set_x(char **map, int x, int y)
{
  if (map[y - 1][(x - 1) * 2] == '.' || map[y - 1][(x - 1) * 2] == 'o')
    map[y - 1][(x - 1) * 2] = 'o';
  else
    map[y - 1][(x - 1) * 2] = 'x';
  return (map);
}

int	follow(int pid, char **map, char **enemy_map)
{
  char	*s;
  int	x;
  int	y;

  while (42)
    {
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
      if (win(map) == 1)
	{
	  freeTable(map);
          freeTable(enemy_map);
	  return (1);
	}
      s = check();
      if (traduction(pid, s) == 1)
	return (-1);
      g_global = 0;
      while (g_global == 0)
	pause();
      enemy_map = set_enemy(enemy_map, s[0] - 'A', s[1] - '0');
      if (win(enemy_map) == 1)
	{
	  freeTable(map);
	  freeTable(enemy_map);
	  return (0);
	}
      free(s);
      printmap(map, enemy_map, 1);
    }
}

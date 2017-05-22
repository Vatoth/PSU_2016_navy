/*
** player1.c for player1.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Thu Feb  2 10:52:35 2017 Quentin Sonnefraud
** Last update Mon Feb 20 11:53:01 2017 Vatoth
*/

#include "navy.h"

extern	int g_global;

int     bloup_one(char **map, char **enemy_map)
{
  int   pid;
  int   i;

  my_printf("my_pid: %i\n", (int)getpid());
  my_putstr("waiting for enemy connexion...\n");
  get_sig();
  pause();
  pid = g_global;
  g_global = 0;
  if (put_sig(pid, 1) == -1)
    return (-1);
  my_putstr("enemy connected\n");
  printmap(map, enemy_map, 0);
  i = follow_one(pid, map, enemy_map);
  return (i);
}

int     player_one(char *path)
{
  char  **map;
  char  **enemy_map;
  char  **pos;
  int   i;

  if ((map = allocation("map", 9, 17)) == NULL)
    return (-1);
  if ((enemy_map = allocation("map", 9, 17)) == NULL)
    return (-1);
  if ((pos = allocation(path, 5, 9)) == NULL)
    return (-1);
  if (check_pos(pos) == -1)
    return (-1);
  i = 0;
  while (pos[i] != NULL)
    if ((map = analyse(my_str_to_wordtab(pos[i++], ':'), map)) == NULL)
      return (-1);
  freeTable(pos);
  i = bloup_one(map, enemy_map);
  return (i);
}

int	traduction(int pid, char *s)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  if (s[0] >= 'A' && s[0] <= 'H')
    x = s[0] - 'A';
  if (s[1] >= '1' && s[1] <= '8')
    y = s[1] - '1';
  while (x >= 0)
    {
      usleep(1000);
      if (put_sig(pid, 0) == -1)
	return (-1);
      x--;
    }
  usleep(1000);
  if (follow_traduction(y, pid) == -1)
    return (-1);
  my_putstr(s);
  return (0);
}

char	**set_enemy(char **map, int x, int y)
{
  if (g_global == 1)
    {
      my_putstr(": missed\n");
      map[y - 1][(x) * 2] = 'o';
    }
  if (g_global == 2)
    {
      my_putstr(": hit\n");
      map[y - 1][(x) * 2] = 'x';
    }
  return (map);
}

int	follow_one(int pid, char **map, char **enemy_map)
{
  char	*s;

  while (42)
  {
    s = check();
    if (traduction(pid, s) == 1)
      return (-1);
    g_global = 0;
    while (g_global == 0)
      pause();
    enemy_map = set_enemy(enemy_map, s[0] - 'A', s[1] - '0');
    if (win(enemy_map) == 1)
      return (0);
    free(s);
    if (dog_one(pid, map, enemy_map) == 1)
      return (1);
  }
}

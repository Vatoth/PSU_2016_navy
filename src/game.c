/*
** game.c for game.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Jan 31 14:18:54 2017 Quentin Sonnefraud
** Last update Sun Feb 19 09:42:00 2017 Vatoth
*/

#include "navy.h"

int	g_global = 0;

char    **allocation(char *path, int x, int y)
{
  t_al	v;

  v.i = 0;
  if ((v.fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  if ((v.tab1 = (char **)malloc(sizeof(char *) * x)) == NULL)
    return (NULL);
  if ((v.tab2 = (char *)malloc(sizeof(char) * x * y)) == NULL)
    return (NULL);
  my_memset(v.tab2, '\0', x * y);
  while (v.i < x - 1)
    {
      v.tab1[v.i] = &v.tab2[v.i * y];
      v.tab1[v.i++][y] = '\0';
    }
  v.tab1[v.i] = NULL;
  v.i = 0;
  while (v.i < x -1)
    {
      if (read(v.fd, v.tab1[v.i++], y - 1) == -1)
	return (NULL);
    }
  close(v.fd);
  return (v.tab1);
}

t_pos	setpos(char **str)
{
  t_pos	pos;

  if (str[1][0])
    pos.x = (str[1][0] - 'A') * 2;
  if (str[1][1])
    pos.y = str[1][1] - '0' - 1;
  if (str[2][0])
      pos.x1 = (str[2][0] - 'A') * 2;
  if (str[2][1])
    pos.y1 = str[2][1] - '0' - 1;
  return (pos);
}

int	checkpos3(char **s)
{
  if (s[1][0] >= '1' && s[1][0] <= '8')
    my_evil_str(s[0]);
  if ((s[1][0] < 'A') || (s[1][0] > 'H') || (s[1][1] < '1') || (s[1][1] > '8'))
    return (-1);
  if (s[2][0] >= '1' && s[2][0] <= '8')
    my_evil_str(s[1]);
  if ((s[2][0] < 'A') || (s[2][0] > 'H') || (s[2][1] < '1') || (s[2][1] > '8'))
    return (-1);
  return (0);
}

char	**analyse(char **str, char **map)
{
  int	len;
  t_pos	pos;

  len = str[0][0] - '0';
  if (checkpos3(str) == -1)
    {
      my_puterror("wrong boat\n");
      freeTable2(str);
      return (NULL);
    }
  pos = setpos(str);
  if (dudu(pos, len, str, map) == NULL)
    return (NULL);
  return (map);
}

void	printmap(char **map, char **enemy_map, int j)
{
  int	i;
  int	nb;

  if (j == 0)
    my_putstr("my positions:\n");
  else
    my_putstr("\nmy postions:\n");
  my_putstr(" |A B C D E F G H\n-+---------------\n");
  i = 0;
  nb = 1;
  while (map[i] != NULL)
    my_printf("%i|%s", nb++, map[i++]);
  my_putstr("\nenemy's positions:\n");
  i = 0;
  nb = 1;
  my_putstr(" |A B C D E F G H\n-+---------------\n");
  while (enemy_map[i] != NULL)
    my_printf("%i|%s", nb++, enemy_map[i++]);
}

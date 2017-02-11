/*
** game.c for game.c in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Jan 31 14:18:54 2017 Quentin Sonnefraud
** Last update Fri Feb 10 23:02:30 2017 Quentin Sonnefraud
*/

#include "navy.h"

int	g_global = 0;

int	main(int argc, char **argv)
{
  int	check;

  if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
      && argv[1][2] == '\0')
    check = print_h();
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

char    **allocation(char *path, int x, int y)
{
  char	**tab1;
  char	*tab2;
  int	i;
  int	fd;

  i = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  if ((tab1 = (char **)malloc(sizeof(char *) * x)) == NULL)
    return (NULL);
  if ((tab2 = (char *)malloc(sizeof(char) * x * y)) == NULL)
    return (NULL);
  my_memset(tab2, '\0', x * y);
  while (i < x - 1)
    {
      tab1[i] = &tab2[i * y];
      tab1[i++][y] = '\0';
    }
  tab1[i] = NULL;
  i = 0;
  while (i < x -1)
    {
      if (read(fd, tab1[i++], y - 1) == -1)
	return (NULL);
    }
  close(fd);
  return (tab1);
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
  if (pos.x == pos.x1)
    {
      while (len > 0)
	{
	  map[pos.y++][pos.x] = str[0][0];
	  len--;
	}
    }
  else if (pos.y == pos.y1)
    {
      while (len > 0)
	{
	  map[pos.y][pos.x] = str[0][0];
	  pos.x = pos.x + 2;
	  len--;
	}
    }
  freeTable2(str);
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

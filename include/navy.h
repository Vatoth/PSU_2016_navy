/*
** navy.h for navy.h in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Tue Jan 31 15:00:15 2017 Quentin Sonnefraud
** Last update Sun Feb 19 10:24:52 2017 Vatoth
*/

#ifndef NAVY_H_
# define NAVY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

typedef struct	s_al
{
  char		**tab1;
  char		*tab2;
  int		i;
  int		fd;
}		t_al;

typedef struct  s_tab
{
  char          **array;
  int           nb;
  int           i;
  int           y;
  int           k;
}               t_tab;

typedef struct	s_pos
{
  int	x;
  int	y;
  int	x1;
  int	y1;
}		t_pos;

char    **cat_balls(t_pos pos, int len, char **str, char **map);
int     check_lol(char *s);
char    **dudu(t_pos pos, int len, char **str, char **map);
void    my_puterror(char *str);
int     my_printf(char *flag, ...);
char    *check(void);
char    **set_enemy(char **map, int x, int y);
char    **set_x(char **map, int x, int y);
int    traduction(int  pid, char *s);
int     check_hit(char **map, int x, int y, int pid);
char	*get_next_line(int fd);
void    freeTable(char **tableau);
char    **my_str_to_wordtab(char *str, char separator);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nbr);
void    *my_memset(void *str, int c, size_t n);
int     player_one(char *path);
int	player_two(int pid, char *path);
void	freeTable2(char **tab);
char    **allocation(char *path, int x, int y);
char    **analyse(char **str, char **map);
void    printmap(char **map, char **enemy_map, int j);
int	my_atoi(char *str);
void	get_pid(void);
int	put_sig(int pid, int nb);
int     follow_one(int  pid, char **map, char **enemy_map);
int     follow(int  pid, char **map, char **enemy_map);
void    get_sig(void);
int     my_strlen(char *str);
void    my_evil_str(char *str);
void	my_strcapitalize(char *str);
void	print_h(void);
int	win(char **str);
int     check_pos(char **pos);
int     meow(int len, int i);
int     dog_one(int pid, char **map, char **enemy_map);
int     follow_traduction(int y, int pid);
int     meow(int len, int i);
char    **dudu(t_pos pos, int len, char **str, char **map);
void    dog_two(char **map, int pid);

#endif /* !NAVY_H_ */

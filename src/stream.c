/*
** stream.c for stream in /home/Vatoth/PSU_2016_navy
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Feb  1 19:09:25 2017 Quentin Sonnefraud
** Last update Mon Feb 20 11:58:36 2017 Vatoth
*/

#include "navy.h"

extern int g_global;

void		reception(int signum, siginfo_t *info, void *ptr)
{
  static int	nb = 0;
  static int	pid = 0;

  (void)ptr;
  g_global = 0;
  if (signum == SIGUSR2 && nb == 0)
    {
      g_global = info->si_pid;
      pid = info->si_pid;
      nb = 0;
    }
  if (pid == info->si_pid)
  {
    if (signum == SIGUSR1)
      nb++;
    else if (signum == SIGUSR2 && nb != 0)
      {
	g_global = nb;
	nb = 0;
      }
  }
}

void			get_sig(void)
{
  struct sigaction      act;

  act.sa_sigaction = reception;
  act.sa_flags = SA_SIGINFO;
  sigemptyset(&act.sa_mask);
  if (sigaction(SIGUSR1, &act, NULL) == -1)
    my_putstr("ERROR : SIGUSR1\n");
  if (sigaction(SIGUSR2, &act, NULL) == -1)
    my_putstr("ERROR : SIGUSR2\n");
}

int	put_sig(int pid, int nb)
{
  if (pid < 0)
    {
      my_puterror("ERROR : Bad PID\n");
      return (-1);
    }
  if (nb == 0)
    {
      if (kill(pid, SIGUSR1) == -1)
	{
	  my_puterror("ERROR : cannot send SIGUSR1\n");
	  return (-1);
	}
    }
  if (nb == 1)
    {
      if (kill(pid, SIGUSR2) == -1)
	{
	  my_puterror("ERROR : cannot send SIGUSR2\n");
	  return (-1);
	}
    }
  return (0);
}

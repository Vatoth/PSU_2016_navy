/*
** my_strlen.c for my_strlen in /home/Vatoth/CPool_Day04
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Oct  6 21:15:15 2016 Quentin Sonnefraud
** Last update Tue Nov 15 14:03:46 2016 Quentin Sonnefraud
*/

int     my_strlen(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
}

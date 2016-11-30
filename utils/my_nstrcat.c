/*
** my_strcat.c for my_strcat in /home/antonin.rapini/CPool_Day07
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 11:25:45 2016 Antonin Rapini
** Last update Wed Nov 30 15:36:31 2016 Antonin Rapini
*/

#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_nstrcat(int nbr, ...)
{
  va_list list;
  int	i;
  int	size;
  char	**arr;
  char	*final;
  int	j;

  size = 0;
  i = 0;
  arr = malloc(sizeof(char *) * nbr);
  va_start(list, nbr);
  while (i++ < nbr)
    {
      arr[i - 1] = va_arg(list, char *);
      size += my_strlen(arr[i - 1]);
    }
  i = 0;
  final = malloc(sizeof(char) * (size + 1));
  final[size] = '\0';
  j = 0;
  while (j < size)
    {
      while (*arr[i])
	{
	  final[j] = *arr[i];
	  j++;
	  arr[i]++;
	}
      i++;
    }
  //  my_putstr(final);
  return (final);
}

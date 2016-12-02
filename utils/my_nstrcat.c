/*
** my_strcat.c for my_strcat in /home/antonin.rapini/CPool_Day07
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 11:25:45 2016 Antonin Rapini
** Last update Fri Dec  2 20:47:26 2016 Antonin Rapini
*/

#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"

char	*my_fill_string(char **arr, int size)
{
  char	*final;
  int	i;
  int	j;

  if ((final = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(84);
  final[size] = '\0';
  i = 0;
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
  return (final);
}

char	*my_nstrcat(int nbr, ...)
{
  va_list list;
  int	i;
  int	size;
  char	**arr;

  size = 0;
  i = 0;
  if ((arr = malloc(sizeof(char *) * nbr)) == NULL)
    exit(84);
  va_start(list, nbr);
  while (i++ < nbr)
    {
      arr[i - 1] = va_arg(list, char *);
      size += my_strlen(arr[i - 1]);
    }
  return (my_fill_string(arr, size));
}

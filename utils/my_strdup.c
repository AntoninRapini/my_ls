/*
** my_strdup.c for my_strdup in /home/antonin.rapini/CPool_Day08/task01
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 18:40:56 2016 Antonin Rapini
** Last update Thu Dec  1 21:36:21 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;
  int	size;

  i = 0;
  size = my_strlen(src);
  if((dest = malloc((size + 1) * sizeof(char))) == NULL)
    exit(84);
  dest[size] = '\0';
  while(src[i++])
    dest[i - 1] = src[i - 1];
  return (dest);
    
}

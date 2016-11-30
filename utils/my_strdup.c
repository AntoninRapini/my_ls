/*
** my_strdup.c for my_strdup in /home/antonin.rapini/CPool_Day08/task01
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 18:40:56 2016 Antonin Rapini
** Last update Wed Nov 30 11:11:46 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  dest = malloc((my_strlen(src) + 1) * sizeof(char));
  dest[my_strlen(src)] = '\0';
  if (dest == NULL)
    exit (84);
  while(src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
    
}

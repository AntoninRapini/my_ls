/*
** my_nbrlen_base.c for my_nbrlen_base in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Nov 20 15:54:52 2016 Antonin Rapini
** Last update Fri Dec  2 20:41:22 2016 Antonin Rapini
*/

#include <stdlib.h>

char	*my_int_tostr(int nbr)
{
  int	div;
  int	pass;
  char	*str;
  int	i;

  i = 0;
  pass = 1;
  div = 1;
  while (nbr / div >= 10)
    {
      div *= 10;
      pass++;
    }
  if ((str = malloc(sizeof(char) * (pass + 1))) == NULL)
    exit(84);
  str[pass] = '\0';
  while (div >= 1)
    {
      str[i] = nbr/div + '0';
      nbr = nbr % div;
      div = div / 10;
      i++;
    }
  return (str);
}

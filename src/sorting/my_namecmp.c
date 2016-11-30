/*
** my_namecomp.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/sorting
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 10:10:31 2016 Antonin Rapini
** Last update Wed Nov 30 16:17:53 2016 Antonin Rapini
*/

#include "my_fileinfos.h"

int	casefree_cmp(char a, char b)
{
  int	new_a;
  int	new_b;

  new_a = a >= 'A' && a <= 'Z' ? a + 32 : a;
  new_b = b >= 'A' && b <= 'Z' ? b + 32 : b;
  if (new_a == new_b)
    return (1);
  if (new_a < new_b)
    return (0);
  return (-1);
}

int	my_namecmp(t_fileinfos *file1, t_fileinfos *file2)
{
  int	i;

  i = 0;
  while (file1->name[i] && file2->name[i]
	 && casefree_cmp(file1->name[i], file2->name[i]) == 1)
    i++;
  return (casefree_cmp(file1->name[i], file2->name[i]) < 0);
}

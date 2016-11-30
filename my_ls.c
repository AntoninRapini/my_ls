/*
** my_ls.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Nov 28 16:54:07 2016 Antonin Rapini
** Last update Wed Nov 30 16:45:37 2016 Antonin Rapini
*/

#include "sources.h"
#include "my_options.h"
#include "my_list.h"

int		main(int ac, char **av)
{
  int		i;
  t_options	*options;

  i = 1;
  options = my_set_options(ac, av, &i);
  my_display(options, i, ac, av);
  return (0);
}

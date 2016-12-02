/*
** my_display.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Nov 30 16:33:23 2016 Antonin Rapini
** Last update Fri Dec  2 15:29:32 2016 Antonin Rapini
*/

#include "my_options.h"
#include "sources.h"
#include <stdlib.h>
#include "utils.h"

void		my_display(t_options *options, int i, int ac, char **av)
{
  t_list	*files;
  int		multiple;

  multiple = ac - i > 1 ? 1 : 0;
  if (i == ac)
    {
      av[i] = malloc(sizeof(char) * 2);
      av[i][0] = '.';
      av[i][1] = '\0';
      ac++;
    }
  while (i < ac)
    {
      if ((files = my_create_list(options, av[i])) != NULL)
	{
	  if ((options->recursive || multiple) && !options->show_self)
	    my_putstr(my_nstrcat(3, "\n", av[i], ":\n"));
	  options->my_display(options, files);
	}
      i++;
    }
}

/*
** my_display.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Nov 30 16:33:23 2016 Antonin Rapini
** Last update Fri Dec  2 10:33:08 2016 Antonin Rapini
*/

#include "my_options.h"
#include "sources.h"
#include <stdlib.h>

void		my_display(t_options *options, int i, int ac, char **av)
{
  t_list	*files;

  if (ac > 1 && i != ac)
    {
      while (i < ac)
	{
	  if ((files = my_create_list(options, av[i])) != NULL)
	  {
	    options->my_display(options, files);
	  }
	  i++;
	}
    }
  else
    {
      if ((files = my_create_list(options, ".")) != NULL)
	{
	  options->my_display(options, files);
	}
    }
}

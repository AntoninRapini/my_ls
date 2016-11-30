/*
** my_display.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Nov 30 16:33:23 2016 Antonin Rapini
** Last update Wed Nov 30 16:48:12 2016 Antonin Rapini
*/

#include "my_options.h"
#include "sources.h"

void		my_display(t_options *options, int i, int ac, char **av)
{
  t_list	*files;

  if (ac > 1 && i != ac)
    {
      while (i < ac)
	{
	  files = my_create_list(options, av[i]);
	  options->my_display(options, files);
	  i++;
	}
    }
  else
    {
      files = my_create_list(options, ".");
      options->my_display(options, files);
    }
}

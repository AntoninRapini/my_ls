/*
** set_options.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 11:05:37 2016 Antonin Rapini
** Last update Thu Dec  1 23:35:48 2016 Antonin Rapini
*/

#include "my_options.h"
#include "my_sorting.h"
#include "my_fileinfos.h"
#include <stdlib.h>

void my_set_default_options(t_options *options)
{
  options->reversed = 0;
  options->my_compfnc = &my_namecmp;
  options->show_filetype = 0;
  options->my_display = &my_display_default;
  options->recursive = 0;
  options->hide_owner = 0;
  options->show_self = 0;
  options->show_accesstime = 0;
  options->show_hidden = 0;
}

void check_bonus_options(t_options *options, char flag)
{
  if (flag == 'u')
    options->my_compfnc = &my_atimecmp;
  else if (flag == 'F')
    options->show_filetype = 1;
  else if (flag == 'g')
    {
      options->hide_owner = 1;
      options->my_display = &my_display_line;
    }
  else if (flag == 'f')
    {
      options->my_compfnc = &my_nocmp;
      options->show_hidden = 1;
    }
  else
    exit(84);
}

void check_options(t_options *options, char flag)
{
  if (flag == 'r')
    options->reversed = 1;
  else if (flag  == 'R')
    options->recursive = 1;
  else if (flag == 'l')
    options->my_display = &my_display_line;
  else if (flag == 'd')
    options->show_self = 1;
  else if (flag == 't')
    options->my_compfnc = &my_mtimecmp;
  else
    check_bonus_options(options, flag);
}

void	my_parse_options(t_options *options, int ac, char **av, int *i)
{
  int	j;

  while (*i < ac)
    {
      j = 1;
      if (av[*i][0] == '-')
	{
	  while (av[*i][j])
	    {
	      check_options(options, av[*i][j]);
	      j++;
	    }
	  (*i)++;
	}
      else
	return ;
    }
}

t_options	*my_set_options(int ac, char **av, int *i)
{
  t_options	*options;

  options = malloc(sizeof(t_options));
  my_set_default_options(options);
  my_parse_options(options, ac, av, i);
  if (options->my_compfnc == &my_atimecmp
      && options->my_display == &my_display_line)
    {
      options->my_compfnc = &my_namecmp;
      options->show_accesstime = 1;
    }
  return (options);
}

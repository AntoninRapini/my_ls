/*
** my_display_recursive.c for my_display_recursive in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Dec  2 10:57:53 2016 Antonin Rapini
** Last update Fri Dec  2 12:03:38 2016 Antonin Rapini
*/

#include "my_options.h"
#include "my_list.h"
#include "sources.h"
#include <stdlib.h>
#include "utils.h"

void	my_display_recursive(t_options *options, t_list *files)
{
  t_list *list;

  while (files != NULL)
    {
      if (S_ISDIR(files->fileinfos->stat_data->st_mode) && files->fileinfos->name[0] != '.')
	{
	  my_putchar('\n');
	  my_putstr(files->fileinfos->path);
	  my_putstr (":\n");
	  list = my_create_list(options, files->fileinfos->path);
	  options->my_display(options, list);
	}
      files = files->next;
    }
}

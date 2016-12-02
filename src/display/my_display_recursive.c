/*
** my_display_recursive.c for my_display_recursive in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Dec  2 10:57:53 2016 Antonin Rapini
** Last update Fri Dec  2 14:08:57 2016 Antonin Rapini
*/

#include "my_options.h"
#include "my_list.h"
#include "sources.h"
#include <stdlib.h>
#include "utils.h"

void	my_display_recursive(t_options *options, t_list *files)
{
  t_list *list;
  ino_t  start_inode;

  start_inode = files->fileinfos->stat_data->st_ino;
  while (files != NULL)
    {
      if (S_ISDIR(files->fileinfos->stat_data->st_mode)
	  && files->fileinfos->stat_data->st_ino != start_inode)
	{
	  if (files->fileinfos->name[0] != '.')
	    {
	      my_putchar('\n');
	      my_putstr(files->fileinfos->path);
	      my_putstr (":\n");
	      list = my_create_list(options, files->fileinfos->path);
	      if (list != NULL)
		options->my_display(options, list);
	    }
	}
      files = files->next;
    }
}

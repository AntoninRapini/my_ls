/*
** my_display_default.c for my_display_default in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 22:29:12 2016 Antonin Rapini
** Last update Fri Dec  2 15:20:49 2016 Antonin Rapini
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my_list.h"
#include "my_options.h"
#include "my_fileinfos.h"
#include "utils.h"
#include <time.h>
#include "sources.h"

void	my_display_default(t_options *options, t_list *list)
{
  t_list *start;

  start = list;
  while (list != NULL)
    {
      if (options->show_hidden ||
	  (list->fileinfos->name[0] != '.' || options->show_self))
	{
	  my_putstr(list->fileinfos->name);
	  my_putchar(list->fileinfos->typespecifier);
	  my_putchar('\n');
	}
      list = list->next;
    }
  if (options->recursive && !options->show_self)
    my_display_recursive(options, start);
}

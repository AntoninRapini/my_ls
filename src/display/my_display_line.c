/*
** my_display_line.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 22:29:12 2016 Antonin Rapini
** Last update Fri Dec  2 14:20:20 2016 Antonin Rapini
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my_list.h"
#include "my_options.h"
#include "my_fileinfos.h"
#include "utils.h"
#include "sources.h"

void	my_display_line(t_options *options, t_list *list)
{
  t_list *start;

  start = list;
  if (!options->show_self)
    my_showblocks(list);
  while (list != NULL)
    {
      if (options->show_hidden ||
	  (list->fileinfos->name[0] != '.' || options->show_self))
	{
	  my_putstr(my_format_line(options, list->fileinfos));
	  my_putchar('\n'); 
	}
      list = list->next;
    }
  if (options->recursive)
    my_display_recursive(options, start);
}

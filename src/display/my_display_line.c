/*
** my_display_line.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 22:29:12 2016 Antonin Rapini
** Last update Thu Dec  1 21:18:53 2016 Antonin Rapini
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
  if (options == NULL && list == NULL)
    return ;
  while (list != NULL)
    {
      if (options->show_hidden || list->fileinfos->name[0] != '.')
	{
	  my_putstr(my_format_line(options, list->fileinfos));
	  my_putchar('\n'); 
	}
      list = list->next;
    }
  return ;
}

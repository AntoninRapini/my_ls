/*
** my_display_default.c for my_display_default in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 22:29:12 2016 Antonin Rapini
** Last update Wed Nov 30 16:05:28 2016 Antonin Rapini
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my_list.h"
#include "my_options.h"
#include "my_fileinfos.h"
#include "utils.h"

void	my_display_default(t_options *options, t_list *list)
{
  while (list != NULL)
    {
      if (options->show_hidden)
	{
	  my_putstr(list->fileinfos->name);
	  my_putstr(" ");
	}
      else if (list->fileinfos->name[0] != '.')
	{
	  my_putstr(list->fileinfos->name);
	  my_putstr(" ");
	}
      list = list->next;
      if (options->show_filetype)
	return ;
    }
}

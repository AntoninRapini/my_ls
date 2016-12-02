/*
** my_create_list.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 17:15:17 2016 Antonin Rapini
** Last update Fri Dec  2 14:36:20 2016 Antonin Rapini
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_options.h"
#include "utils.h"
#include "sources.h"

void		my_create_listelement
(t_list **list, struct dirent *entry, char *path, t_options *options)
{
  t_list	*element;

  if((element = malloc(sizeof(t_list *))) == NULL)
    exit(84);
  element->fileinfos = my_create_fileinfos(entry->d_name, path, options, 1);
  if (element->fileinfos != NULL)
    {
      element->next = *list;
      *list = element;
    }
}

void	set_previous(t_list *list)
{
  list->previous = NULL;
  while (list->next != NULL)
    {
      list->next->previous = list;
      list = list->next;
    }
}

t_list		*my_create_list(t_options *options, char *path)
{
  t_list	*list;
  DIR		*dir;
  struct dirent *entry;

  dir = opendir(path);
  if (dir == NULL || options->show_self == 1)
    {
      list = malloc(sizeof(t_list *));
      list->fileinfos = my_create_fileinfos(path, path, options, 0);
      if (list != NULL)
	list->next = NULL;
    }
  else
    {
      list = NULL;
      while ((entry = readdir(dir)) != NULL)
	my_create_listelement(&list, entry, path, options);
    }
  if (list != NULL)
    {
      set_previous(list);
      my_sort_list(&list, options);
    }
  return (list);
}

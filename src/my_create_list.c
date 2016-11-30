/*
** my_create_list.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 17:15:17 2016 Antonin Rapini
** Last update Wed Nov 30 19:07:51 2016 Antonin Rapini
*/

#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_options.h"
#include "utils.h"
#include <stdio.h>
#include "sources.h"

t_fileinfos	*create_fileinfos(char *filename, char *path)
{
  t_fileinfos	*fileinfos;
  struct stat	*sb;
  struct passwd *pwd;
  struct group	*grp;

  sb = malloc(sizeof(struct stat));
  fileinfos = malloc(sizeof(t_fileinfos));
  if (fileinfos == NULL || sb == NULL)
    exit (84);
  if (stat(my_nstrcat(3, path, "/", filename), sb) == -1)
    return (NULL);
  pwd = getpwuid(sb->st_uid);
  grp = getgrgid(sb->st_gid);
  if (pwd == NULL || grp == NULL)
    exit (84);
  fileinfos->owner = my_strdup(pwd->pw_name);
  fileinfos->group = my_strdup(grp->gr_name);
  fileinfos->stat_data = sb;
  fileinfos->name = filename;
  return (fileinfos);
}

void		my_create_listelement(t_list **list, struct dirent *entry, char *path)
{
  t_list	*element;

  element = malloc(sizeof(t_list *));
  if (element == NULL)
    exit(84);
  element->fileinfos = create_fileinfos(entry->d_name, path);
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
      list->fileinfos = create_fileinfos(path, path);
      list->next = NULL;
    }
  else
    {
      list = NULL;
      while ((entry = readdir(dir)) != NULL)
	my_create_listelement(&list, entry, path);
    }
  set_previous(list);
  my_sort_list(&list, options);
  return (list);
}

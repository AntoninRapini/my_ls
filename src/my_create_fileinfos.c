/*
** my_create_list.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 17:15:17 2016 Antonin Rapini
** Last update Fri Dec  2 21:14:34 2016 Antonin Rapini
*/

#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_list.h"
#include "my_options.h"
#include "utils.h"
#include "sources.h"

char	*get_linkname(char *path, struct stat *sb)
{
  char	*buffer;
  int	len;
  char	*name;

  if (S_ISLNK(sb->st_mode))
    {
      if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
	exit(84);
      if ((len = readlink(path, buffer, 1024 - 1)) != -1)
	buffer[len] = '\0';
      else
	exit(84);
      name = my_strdup(buffer);
      free(buffer);
      return (name);
    }
  return (NULL);
}

char	*create_filepath(char *path, char *name)
{
  return (my_nstrcat
	  (3, path, path[my_strlen(path) - 1] != '/' ? "/" : "\0", name));
}

struct stat	*my_get_stat(char *path, char *name, int dir, t_fileinfos *infos)
{
  struct stat	*sb;
  char		*filepath;

  if ((sb = malloc(sizeof(struct stat))) == NULL)
    exit(84);
  if (dir)
    {
      filepath = create_filepath(path, name);
      infos->path = filepath;
      infos->is_dir = 1;
      if (lstat(filepath, sb) != -1)
	infos->links_to = get_linkname(filepath, sb);
      else
	return (NULL);
    }
  else
    if (lstat(path, sb) != -1)
      {
	infos->is_dir = 0;
	infos->path = path;
	infos->links_to = get_linkname(path, sb);
      }
    else
      return (NULL);
  return (sb);
}

t_fileinfos	*my_create_fileinfos
(char *filename, char *path, t_options *optns, int is_dir)
{
  t_fileinfos	*fileinfos;
  struct stat	*sb;
  struct passwd *pwd;
  struct group	*grp;

  if ((fileinfos = malloc(sizeof(t_fileinfos))) == NULL)
    exit(84);
  if ((sb = my_get_stat(path, filename, is_dir, fileinfos)) == NULL)
    exit(84);
  if ((pwd = getpwuid(sb->st_uid)) == NULL)
    return (NULL);
  if ((grp = getgrgid(sb->st_gid)) == NULL)
    return (NULL);
  fileinfos->typespecifier = my_get_typespecifier(optns, sb->st_mode);
  fileinfos->owner = optns->hide_owner ? "\0" : my_strdup(pwd->pw_name);
  fileinfos->group = my_strdup(grp->gr_name);
  fileinfos->stat_data = sb;
  fileinfos->name = filename;
  return (fileinfos);
}

/*
** my_format_line.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  1 17:30:50 2016 Antonin Rapini
** Last update Sun Dec  4 18:10:39 2016 Antonin Rapini
*/

#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_options.h"
#include "my_fileinfos.h"
#include "utils.h"

char my_get_filetype(mode_t st_mode)
{
  if (S_ISREG(st_mode))
    return ('-');
  if (S_ISDIR(st_mode))
    return ('d');
  if (S_ISCHR(st_mode))
    return ('c');
  if (S_ISBLK(st_mode))
    return ('b');
  if (S_ISFIFO(st_mode))
    return ('p');
  if (S_ISLNK(st_mode))
    return ('l');
  if (S_ISSOCK(st_mode))
    return ('s');
  return ('?');
}

char	*my_format_rights(mode_t st_mode)
{
  char	*rights;

  if ((rights = malloc(sizeof(char) * 11)) == NULL)
    exit(84);
  rights[0] = my_get_filetype(st_mode);
  rights[1] = st_mode & S_IRUSR ? 'r' : '-';
  rights[2] = st_mode & S_IWUSR ? 'w' : '-';
  rights[3] = st_mode & S_IXUSR ? 'x' : '-';
  rights[4] = st_mode & S_IRGRP ? 'r' : '-';
  rights[5] = st_mode & S_IWGRP ? 'w' : '-';
  rights[6] = st_mode & S_IXGRP ? 'x' : '-';
  rights[7] = st_mode & S_IROTH ? 'r' : '-';
  rights[8] = st_mode & S_IWOTH ? 'w' : '-';
  rights[9] = st_mode & S_IXOTH ? 'x' : '-';
  if (st_mode & S_ISVTX)
    rights[9] = rights[9] == 'x' ? 't' : 'T';
  if (st_mode & S_ISUID)
    rights[3] = rights[3] == 'x' ? 's' : 'S';
  if (st_mode & S_ISGID)
    rights[6] = rights[6] == 'x' ? 's' : 'S';
  rights[10] = '\0';
  return (rights);
}

char	*my_format_time(t_options *options, t_fileinfos *infos)
{
  char	*nonformatted;
  char	*formatted;
  int	i;

  i = 0;
  nonformatted = options->show_accesstime ? ctime(&(infos->stat_data->st_atime))
    : ctime(&(infos->stat_data->st_mtime));
  if ((formatted = malloc(sizeof(char) * 13)) == NULL)
    exit(84);
  formatted[12] = '\0';
  while (i < 12)
    {
      formatted[i] = nonformatted[i + 4];
      i++;
    }
  return (formatted);
}

char	*my_format_line(t_options *options, t_fileinfos *infos)
{
  char	*line;
  char	*rights;
  char	*links;
  char	*size;
  char	*time;

  time = my_format_time(options, infos);
  links = my_int_tostr(infos->stat_data->st_nlink);
  size = my_int_tostr(infos->stat_data->st_size);
  rights = my_format_rights(infos->stat_data->st_mode);
  line = my_nstrcat(16, rights, " ", links, " ", infos->owner,
		    " ", infos->group, " ", size, "\t", time, " ", infos->name,
		    infos->links_to != NULL ? "\0" : &infos->typespecifier,
		    infos->links_to != NULL ? " -> " : "\0",
		    infos->links_to != NULL ? infos->links_to : "\0");
  return (line);
}

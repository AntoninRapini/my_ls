/*
** my_putchar.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  1 17:08:27 2016 Antonin Rapini
** Last update Thu Dec  1 17:09:51 2016 Antonin Rapini
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

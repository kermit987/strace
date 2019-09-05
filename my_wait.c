/*
** my_wait.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Sun Apr 10 08:55:15 2016 Victor Le
** Last update Sun Apr 10 08:56:54 2016 Victor Le
*/

#include <stdio.h>
#include <sys/wait.h>

int	my_wait(int *status)
{
  if (wait(status) == -1)
    {
      perror("wait");
      return (0);
    }
  return (1);
}

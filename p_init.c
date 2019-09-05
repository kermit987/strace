/*
** p_init.c for  in /home/steven/rendu/PSU_2015_strace
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Sun Apr 10 15:25:40 2016 Steven Loo Fat
** Last update Sun Apr 10 23:31:55 2016 Victor Le
*/

#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <strace_cmd.h>

int	init(t_opt opt, pid_t pid)
{
  if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
    {
      perror("ptrace");
      return (1);
    }
  printf("Process %d attached\n", pid);
  strace_father(opt, pid);
  if (ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1)
    {
      perror("ptrace");
      return (1);
    }
  return (0);
}

/*
** strace_cmd_child.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Thu Apr  7 16:47:18 2016 Victor Le
** Last update Sun Apr 10 18:38:51 2016 Steven Loo Fat
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <unistd.h>

int	strace_child(char **av)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    {
      perror("ptrace");
      return (0);
    }
  if (kill(getpid(), SIGSTOP) == -1)
    {
      perror("kill");
      return (0);
    }
  execvp(av[0], av);
  perror("execvp");
  return (0);
}

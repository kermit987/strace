/*
** parse_cmd_line.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 11:43:27 2016 Victor Le
** Last update Sun Apr 10 18:36:07 2016 Steven Loo Fat
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "parse_cmd_line.h"
#include "main.h"

static int	is_arg_number(const char *str)
{
  if (!str)
    return (0);
  while (*str)
    {
      if (!isdigit(*str))
	return (0);
      ++str;
    }
  return (1);
}

static int	option_p_case(t_opt *opt, pid_t *pid, char **av, int *i)
{
  if (*opt & P_OPT)
    {
      printf("./strace: Cannot trace multiple process\n");
      return (0);
    }
  ++(*i);
  if (!is_arg_number(av[*i]))
    {
      printf("./strace: Invalid process id: '%s'\n", av[*i]);
      return (0);
    }
  *pid = atoi(av[*i]);
  *opt |= P_OPT;
  return (1);
}

static int	other_case(char **av, const int i, const t_opt *opt)
{
  if (av[i][0] == '-')
    {
      printf("./strace: invalid option -- '%c'\n", av[i][1]);
      return (0);
    }
  if (*opt & P_OPT)
    {
      printf(STRACE_USAGE);
      return (0);
    }
  return (i);
}

int	parse_cmd_line(int ac, char **av, t_opt *opt, pid_t *pid)
{
  int	i;

  if (!opt || !pid)
    return (0);
  i = 1;
  while (i < ac)
    {
      if (!strncmp("-s", av[i], 2))
	*opt |= S_OPT;
      else if (!strncmp("-p", av[i], 2))
	{
	  if (!option_p_case(opt, pid, av, &i))
	    return (0);
	}
      else
	return (other_case(av, i, opt));
      ++i;
    }
  return (i);
}

/*
** strace_cmd.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 15:38:29 2016 Victor Le
** Last update Sun Apr 10 18:41:39 2016 Steven Loo Fat
*/

#ifndef STRACE_CMD_H_
# define STRACE_CMD_H_

# include "main.h"
# include "parse_cmd_line.h"

int	strace_cmd(const t_opt opt, char **av);
int	strace_father(const t_opt, const pid_t);

#endif /* !STRACE_CMD_H_ */

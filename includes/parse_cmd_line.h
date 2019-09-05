/*
** parse_cmd_line.h for strace in /home/le_l/Workspace/PSU_2015_strace/tmp
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 15:01:26 2016 Victor Le
** Last update Sun Apr 10 18:41:29 2016 Steven Loo Fat
*/

#ifndef PARSE_CMD_LINE_H_
# define PARSE_CMD_LINE_H_

# include <unistd.h>

typedef enum	e_prog_option
  {
    NO_OPT = 0,
    P_OPT = 1,
    S_OPT = P_OPT << 1
  }		t_opt;

int	parse_cmd_line(int ac, char **av, t_opt *opt, pid_t *pid);
#endif /* !PARSE_CMD_LINE_H_ */

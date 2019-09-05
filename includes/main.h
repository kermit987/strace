/*
** main.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Wed Apr  6 16:14:41 2016 Victor Le
** Last update Sat Apr  9 08:19:26 2016 Victor Le
*/

#ifndef MAIN_H_
# define MAIN_H_

# include <sys/user.h>
# include <stddef.h>

# define STRACE_USAGE	("Usage: ./strace [-s] [-p <pid>|<command>]\n")

# define OPCODE_MASK	(0x000000000000ffff)
# define SYSCALL_OPCODE	(0x050f)

typedef struct user_regs_struct	t_regs;
typedef unsigned long long int	t_reg_size;

# define REG_IDX(x)	(offsetof(t_regs, x) / sizeof(t_reg_size))

#endif /* !MAIN_H_ */

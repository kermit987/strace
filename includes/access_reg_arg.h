/*
** access_reg_arg.h for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Fri Apr  8 22:18:19 2016 Victor Le
** Last update Fri Apr  8 22:25:44 2016 Victor Le
*/

#ifndef ACCESS_REG_ARG_H_
# define ACCESS_REG_ARG_H_

# include "main.h"

t_reg_size	access_reg_arg(const t_regs *regs, const int arg_nb);
t_reg_size	get_rip(const t_regs *regs);

#endif /* !ACCESS_REG_ARG_H_ */

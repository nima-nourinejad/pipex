/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/14 13:29:16 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_rule
{
	char	*cmd;
	char	*add;
	char	**args;
	int		f;
	int		x;
}	t_rule;

typedef struct s_io
{
	int	i;
	int	o;
}	t_io;

typedef struct s_ior
{
	t_io	io;
	t_rule	*r1;
	t_rule	*r2;
}	t_ior;

typedef struct s_scape
{
	char	*without;
	char	*index;
}	t_scape;

char	**ft_split_pipex(char const *s, char c);
char	**ft_args0_maker(char *str);
char	**ft_args1_maker(char *str);
char	*ft_pos0_maker(char *str);
char	*ft_pos1_maker(char *str);
t_io	ft_io(char *i, char *o);
char	*ft_scape(char *input);
int		ft_f_path(char *str, char **envp);
int		ft_x_path(char *str, char **envp);
int		ft_f_root(char *str);
int		ft_x_root(char *str);
char	*ft_add_maker(char *str, char **envp);
char	**ft_args0_maker(char *str);
char	**ft_args1_maker(char *str);
char	**ft_args2_maker(char *str);
char	**ft_args3_maker(char *str);
t_rule	*ft_rule0_maker(const char *str, char **envp);
t_rule	*ft_rule1_maker(const char *str, char **envp);
t_rule	*ft_rule2_maker(const char *str);
t_rule	*ft_rule3_maker(const char *str);
void	ft_rule_remover(t_rule *rule);
int		ft_find_max4(int x1, int x2, int x3, int x4);
t_rule	*ft_final_rule(char *str, char **envp);
void	ft_rule_check(t_rule *r);
void	ft_exec_rule2(int i, int o, t_ior ior, char **envp);
int		ft_exec_rule3(int i, int o, t_ior ior, char **envp);
char	**ft_free_split(char ***m, int j);
int		ft_triger_maker_sp(int triger, char c, char before_c, char divider);
t_ior	*ft_free_exit_ior(t_ior ior, int ex);
void	ft_close_fd(int in, int out);
void	ft_free_doule_pointer(char **m);
void	ft_free_ior(t_ior ior);
void	ft_free_ior_unlink(t_ior ior);
void	ft_free_rule_fd(t_rule *r, int fd);
int		ft_check_f(char *join, char **path);
int		ft_check_x(char *join, char **path);
char	*ft_check_add(char *join, char **path);
int		ft_all_delimiter(char const *s, char c);
char	**ft_split_all_delimiter(char const *s);
void	ft_free_ior1(t_ior ior);
void	ft_free_ior2(t_ior ior);

#endif // PIPEX_H
#ifndef LIBARI
# define LIBARI

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
//======================get_next_line.src==============
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef enum e_success
{
	ERROR = 0,
	SUCCESS,
	CONTINUE
}t_success;

typedef struct s_gnl_list
{
	ssize_t				fd;
	ssize_t				buf_len;
	char				*buf;
	struct s_gnl_list	*next;
	struct s_gnl_list	*prev;
}t_g_list;


t_success	join_str(t_g_list **fd_lst, char **str, ssize_t read_len);
t_success	read_str(t_g_list **fd_lst, int fd);
char		*set_save(t_g_list **fd_lst, char **ret, ssize_t ret_len);
ssize_t		get_ret_len(t_g_list **fd_lst);
char		*ret_str(t_g_list **head, t_g_list **fd_lst);

t_success	free_lst(t_g_list **head, t_g_list **fd_lst);
t_success	get_g_list(t_g_list **head, t_g_list **fd_lst, int fd);
void		set_fd_list(t_g_list **fd_lst, t_g_list *prev, int fd);
//===================================================


// main proto
char		*ari_get_next_line(int fd);
size_t      ari_putstr_fd(const char *s, int fd);
size_t      ari_putendl_fd(const char *s, int fd);

#endif

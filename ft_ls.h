#ifndef FT_LS_H
# define FT_LS_H
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include "libft.h"

typedef struct		s_infos
{
	char			*path;
	char			*filename;
	char			*acces;
	char			*links;
	char			*usrname;
	char			*usrgrp;
	char			*bytesize;
	char			*date_formated;
	time_t			epoch_time;
	u_long 			blksize;
}					t_infos;
typedef struct		s_lens
{
	size_t			filename_len;
	size_t			links_len;
	size_t			username_len;
	size_t			usrgrp_len;
	size_t			bytesize_len;
}					t_len;
typedef struct		s_pque
{
					void			*content;
					size_t			content_size;
					int				content_type;
					t_infos			*infos;
					struct s_pque	*next;
}
					t_lista;

t_infos	*build_data(struct stat *s_stat, char *usr, char *grp, char *path);
t_infos *grab_infos(char *path);
char			*ft_itoa_long(long long n);

char *ft_filename(char *path);

char *ft_build_acces(mode_t mode);
char type_helper(mode_t mode);

char **interpret_args(int argc, char **argv);
void sort_matrix(char **matrix);

void paths_now_what(char **paths, int d);
void print_dir(DIR *dr, char *dir_path);
t_len *ft_build_print_data(t_lista *lst, char *path);
void ft_print(t_lista *list, t_len *lens);
void lst_add(t_lista **list, struct dirent *d);

#endif

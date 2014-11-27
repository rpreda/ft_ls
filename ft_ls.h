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

typedef struct		s_pque
{
					void *content;
					size_t content_type;
					int	content_type;
					struct s_lista *next;
}
					t_lista;

t_infos	*build_data(struct stat *s_stat, char *usr, char *grp, char *path);
t_infos *grab_infos(char *path);

char *ft_filename(char *path);

char *ft_build_acces(mode_t mode);
char type_helper(mode_t mode);

char **interpret_args(int argc, char **argv);
void sort_matrix(char **matrix);

#endif

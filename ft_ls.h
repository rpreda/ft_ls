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
	char			*date_fromated;
	struct timespec	epoch_time;
	u_long 			blksize;
}					t_infos;

t_infos	*build_data(struct stat *s_stat, char *usr, char *grp, char *path);
t_infos *grab_infos(char *path, int type);

char *ft_filename(char *path);

char *ft_build_acces(mode_t mode);
char type_helper(mode_t mode);

#endif
#include "ft_ls.h"
// NEED PATH CLEANING FUNCTION FOR THE dir////// (!!!!!) filename fails else
char *ft_filename(char *path)
{
	char	*found;

	found = ft_strrchr(path, '/');
	if(!found)
		return (ft_strdup(path));
	else
		return (ft_strdup(found));	
	return (NULL);
}
char type_helper(mode_t mode)//type helper may land me -42
{
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISREG(mode))
		return ('-');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}
char *ft_build_acces(mode_t mode)
{
	char	*acces;
	int		i;

	i = 1;
	acces = NULL;
	acces = (char *)malloc(11);
	acces[10] = '\0';
	acces[0] = type_helper(mode);
	while (i<10)
		acces[i++] = '-';
	if (mode & S_IRUSR)
		acces[1] = 'r';
	if (mode & S_IWUSR)
		acces[2] = 'w';
	if (mode & S_IXUSR)
		acces[3] = 'x';
	if (mode & S_IRGRP)
		acces[4] = 'r';
	if (mode & S_IWGRP)
		acces[5] = 'w';
	if (mode & S_IXGRP)
		acces[6] = 'x';
	if (mode & S_IROTH)
		acces[7] = 'r';
	if (mode & S_IWOTH)
		acces[8] = 'w';
	if (mode & S_IXOTH)
		acces[9] = 'x';
	return (acces);
		
}
t_infos	*build_data(struct stat *s_stat, char *usr, char *grp, char *path)
{
	t_infos *t_inf;

	t_inf = (t_infos *)malloc(sizeof(t_infos));
	t_inf->usrname = ft_strdup(usr);
	t_inf->usrgrp = ft_strdup(grp);
	t_inf->filename = ft_filename(path);
	t_inf->acces = ft_build_acces(s_stat->st_mode);
	t_inf->links = ft_itoa((int)s_stat->st_nlink);
	return (t_inf);
}
t_infos *grab_infos(char *path, int type)
{
	struct stat		*s_stat;
	struct passwd	*s_passwd;
	struct group	*s_group;
	t_infos			*t_nf;

	s_stat = (struct stat *)malloc(sizeof(struct stat));
	s_passwd = (struct passwd *)malloc(sizeof(struct passwd));
	s_group = (struct group *)malloc(sizeof(struct group));
	if (type)
	{
		if (stat(path, s_stat) == 0)
		{
			s_passwd = getpwuid(s_stat->st_uid);
			s_group = getgrgid(s_passwd->pw_gid);
		}
		else
		{
			perror("ft_ls");//Handle errors
			return (NULL);
		}
	}
	else
	{
		if (stat(path, s_stat) == 0)
		{
			s_passwd = getpwuid(s_stat->st_uid);
			s_group = getgrgid(s_passwd->pw_gid);
		}
		else
		{
			perror("ft_ls");//Handle errors
			return (NULL);//VERY IMPORTANT
		}
	}
	t_nf = build_data(s_stat, s_passwd->pw_name, s_group->gr_name, path);
	free(s_stat);
	return (t_nf);
}
int main(int argc, char **argv)
{
	t_infos *ret;

	ret = grab_infos(argv[1], 1);
	(void)argc;
	printf("%s\n", ret->usrname);//username working
	printf("%s\n", ret->usrgrp);//group working
	printf("%s\n", ret->filename);//filename works
	printf("%s\n", ret->acces);//acces works
	printf("%s\n", ret->links);//link number works
	return (0);
}

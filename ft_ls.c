#include "ft_ls.h"
int g_sargs;
int g_pargs;
int g_oargs;
int g_hargs;

void arg_interpret(char *s)
{
	while (*s++)
	{
		if (*s == 'l')
			g_pargs = 1;
		if (*s == 'a')
			g_hargs = 1;
		if (*s == 'R')
			g_sargs = 1;
		if (*s == 'r')
			g_oargs = 1;
		if (*s == 't')
			g_oargs = 2;
	}
}

char **interpret_args(int argc, char **argv)
{
	int found_file;
	int i;
	char **ret;
	int k;

	i = 1;
	k = 0;
	ret = (char **)malloc(sizeof(char *) * 100);
	found_file = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			arg_interpret(argv[i]);
		else
		{
			ret[k] = ft_strdup(argv[i]);
			k++;
		}
		i++;
	}
	if(!k)
	{
		ret[k] = ".";
		k = 1;
	}
	ret[k] = NULL;
	return (ret);
}

int main(int argc, char **argv)
{
	char	**paths;
	int		d_names;

	paths = interpret_args(argc, argv);
	sort_matrix(paths);
	if (paths[1])
		d_names = 1;
	else
		d_names = 0;
	/*
	printf("s_ %d p_ %d o_ %d h_ %d\n", g_sargs, g_pargs, g_oargs, g_hargs);
	while (paths[i])
	{
		printf("path-> %s\n", paths[i]);
		i++;
	}*/
	paths_now_what(paths, d_names);
	return (0);
}

#include "ft_ls.h"

char *interpret_args(int argc, char **argv, int *s_args, int *p_args, int *o_args)
{
	int found_file;
	int i;

	i = 0;
	found_file = 0;
	*s_args = 0;
	*p_args = 0;
	*o_args = 0;
	while (i < argc)
	{
		if (argv
	}
}
int main(int argc, char **argv)
{
	char	*path;
	int		source_args;
	int		print_args;
	int		order_args;

	path = interpret_args(argc, argv, &source_args, &print_args, &order_args);
	return (0);
}

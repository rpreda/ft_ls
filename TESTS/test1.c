#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
	DIR *dir;
	struct dirent *d_en;
	
	dir = opendir(".");
	if (!dir)
		exit(1);
	while ((d_en = readdir(dir)) != NULL)
		printf("%s %d %d \n", d_en->d_name, d_en->d_type, d_en->d_reclen);
	printf("%d \n", DT_REG);
	return (0);
}

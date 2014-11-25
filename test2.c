#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

int main()
{
	struct stat *buf;
	struct passwd *buf2;
	uid_t uid;
	buf2 = NULL;

	lstat("test1.c", buf);
	printf("%d HARD LINK NUMBER\n", buf->st_nlink);
	printf("%d UID\n", buf->st_uid);
	printf("%d GID\n", buf->st_gid);
	uid = buf->st_uid;
	buf2 = getpwuid(uid);
	if(buf2)
		printf("%cUsername\n", *buf2->pw_name);
	return (1);
}

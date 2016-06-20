#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define _FILE_ "./log"

int main()
{
	umask(0);
	int fd=open(_FILE_,O_CREAT |O_WRONLY,0644);
	printf("%d\n",fd);
	if(fd<0)
	{
		perror("open");
		return 1;
	}
	close(1);
	int new_fd=dup(fd);
	if(new_fd<0)
	{
		perror("dup");
		return 2;
	}

	close(fd);
	printf("new_fd:%d\n",new_fd);
	int count=0;
	while(count++<100)
	{
		printf("hello world\n");
		fflush(stdout);
	}

	close(new_fd);
	return 0;
}

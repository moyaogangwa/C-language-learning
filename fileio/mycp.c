/*************************************************************************
	> File Name: open.c
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年08月09日 星期三 15时27分42秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char source[20]={0};
	char target[20]={0};
	FILE *fp=fopen("./input.txt","r+");
	fscanf(fp,"%s%s",source,target);	
	printf("%s %s\n",source,target);
	int fd1 = open(source,O_RDWR | O_CREAT,0666);
	int fd2 = open(target,O_RDWR | O_CREAT,0666);
	ssize_t ret = 0;
	char buf[20]={0};
	if(-1 == fd1 || -1 == fd2)
	{
		perror("open fail");
		exit(-1);
	}
	do
	{
		ret = read(fd1,buf,20);
		if(-1 == ret)
		{
			perror("read fail");
			exit(-1);
		}
		ret = write(fd2,buf,ret);
		if(-1 == ret)
		{
			perror("write fail");
			exit(-1);
		}
	
	}while(ret);
	close(fd1);
	close(fd2);
	return 0;
}

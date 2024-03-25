/*********************************************************************************
 *      Copyright:  (C) 2024 linuxer<linuxer@email.com>
 *                  All rights reserved.
 *
 *       Filename:  fork_var.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(29/02/24)
 *         Author:  linuxer <linuxer@email.com>
 *      ChangeLog:  1, Release initial version on "29/02/24 19:54:01"
 *                 
 *******************************************************************************/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



int g_var = 6;
char g_buf[]="a string write to stdout.\n";
int main (int argc,char **argv)
{
	int var = 88;
	pid_t pid;

	if(write(STDOUT_FILENO,g_buf,sizeof(g_buf))-1 < 0)
	{
		printf("write string to stdout error: %s\n",strerror(errno));
		return -1;
	}

	printf("before fork\n");

	if((pid=fork())<0)
	{
		printf("fork() error: %S\n",strerror(errno));
		return -2;
	}
	else if(0 ==pid)
	{
		printf("child process PID[%d] running...\n",getpid());
		g_var ++;
		var ++;
	}
	else
	{
		printf("parent process PID[%d] waiting...\n",getpid());
		sleep(1);
	}
	printf("PID%ld,g_var=%d,var=%d\n",(long)getpid(),g_var,var);
	return 0;
}

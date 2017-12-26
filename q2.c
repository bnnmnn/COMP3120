#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int pid;
	int filedesc = open("q2.txt", O_WRONLY|O_APPEND);
	if (filedesc < 0){
		printf("error\n");
		return 1;
	}
	write(filedesc,"Hello world!\n",36);

	pid = fork();

	if(pid == 0)	write(filedesc,"Child can access\n",20);// both can acess
	else		write(filedesc,"Parent can access\n",20);// if concurrently, writing odd
	return 0;
}

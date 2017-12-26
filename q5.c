#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int a;
	int pid = fork();
	if(pid == 0){	//if use wait() in child, return -1
	printf("This is child\n");
	printf("%d\n",a);
	}
	else{
		a=wait(NULL);	//wait() return is pid
		printf("This is parent\n");
		printf("wait is %d(pid=%d)\n",a,pid);
	}

	return 0;
}

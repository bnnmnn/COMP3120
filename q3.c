#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int pid = fork();
	if(pid == 0){
		printf("hello\n");
	}
	else{
		wait(NULL); // we have to use wait()
		printf("goodbye\n");
	}

	return 0;
}

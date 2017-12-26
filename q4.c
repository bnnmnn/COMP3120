#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int pid = fork();
	if(pid == 0){
		execl("/bin/ls","ls",NULL);
	}
	return 0;
}

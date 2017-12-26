#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(void){
	int x = 100;
	int a = fork();

	if (a == 0){
		printf("this is child, x'c=%d\n",x);
		x=80; //change the value of x
		printf("x'c=%d",x);
	}
	else		printf("this is parent\n"
				"pid is %d, x'p=%d",a,x);//relationless child's value of x

	return 0;
}

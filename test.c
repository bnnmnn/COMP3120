#include <unistd.h>
#include <stdio.h>
#define SYSCALL_NUMBER 332

int main(void)
{
	int n;
	n = syscall(SYSCALL_NUMBER,20);
	printf("jinseobcall return value %d\n",n);
	return 0;
}

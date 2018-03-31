#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";
const int i = 10;

int main() {
	int pid = getpid(); 
foo:
	printf("process id: %d\n", pid);
	printf("global string: %p\n", &global);
	printf("the code: %p\n", &&foo);
	printf("The constant: %p\n", &i);
	
	printf("\n\n /proc/%d/maps \n\n", pid);
	
	char command[50];
	sprintf(command, "cat /proc/%d/maps", pid);
	system(command);
	
	return 0;
}
